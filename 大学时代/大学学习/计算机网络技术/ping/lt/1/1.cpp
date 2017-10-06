#include <stdio.h> 
#include <string.h>
#include <winsock2.h> 
#include <ws2tcpip.h> 
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream.h>
#pragma comment(lib,"ws2_32.lib")

#define IPVER   4           //IP协议预定
#define MAX_BUFF_LEN 65500  //发送缓冲区最大值

typedef struct ip_hdr    //定义IP首部 
{ 
	UCHAR h_verlen;            //4位首部长度,4位IP版本号 
	UCHAR tos;                //8位服务类型TOS 
	USHORT total_len;        //16位总长度（字节） 
	USHORT ident;            //16位标识 
	USHORT frag_and_flags;    //3位标志位 
	UCHAR ttl;                //8位生存时间 TTL 
	UCHAR proto;            //8位协议 (TCP, UDP 或其他) 
	USHORT checksum;        //16位IP首部校验和 
	ULONG sourceIP;            //32位源IP地址 
	ULONG destIP;            //32位目的IP地址 
}IP_HEADER; 

typedef struct tsd_hdr //定义TCP伪首部 
{ 
	ULONG saddr;    //源地址
	ULONG daddr;    //目的地址 
	UCHAR mbz;        //没用
	UCHAR ptcl;        //协议类型 
	USHORT tcpl;    //TCP长度 
}PSD_HEADER; 

typedef struct tcp_hdr //定义TCP首部 
{ 
	USHORT th_sport;            //16位源端口 
	USHORT th_dport;            //16位目的端口 
	ULONG th_seq;                //32位序列号 
	ULONG th_ack;                //32位确认号 
	UCHAR th_lenres;            //4位首部长度/6位保留字 
	UCHAR th_flag;                //6位标志位 
	USHORT th_win;                //16位窗口大小 
	USHORT th_sum;                //16位校验和 
	USHORT th_urp;                //16位紧急数据偏移量 
}TCP_HEADER; 

//CheckSum:计算校验和的子函数 
USHORT checksum(USHORT *buffer, int size) 
{ 
    unsigned long cksum=0; 
    while(size >1) 
    { 
        cksum+=*buffer++; 
        size -=sizeof(USHORT); 
    } 
    if(size) 
    { 
        cksum += *(UCHAR*)buffer; 
    }
    cksum = (cksum >> 16) + (cksum & 0xffff); 
    cksum += (cksum >>16); 
    return (USHORT)(~cksum); 
} 

int ReadData(char *str,int maxlen)
{
	int readlen=0;
	char ch=NULL;
	if(str==NULL||maxlen<=0) 
	{
		printf("ReadData Error!!!\n");
		return 0;//failed
	}
	printf("Input Data(End By Ctrl+Z): \n");
	while(maxlen)
	{
		ch=getchar();
		if(ch==EOF) break;
		str[readlen++]=ch;
		maxlen--;
	}
	str[readlen]=NULL;
	return readlen;
}

int main(int argc, char* argv[]) 
{ 
    WSADATA WSAData; 
    SOCKET sock; 
    
    IP_HEADER ipHeader; 
    TCP_HEADER tcpHeader; 
    PSD_HEADER psdHeader; 

    char Sendto_Buff[MAX_BUFF_LEN];  //发送缓冲区
    unsigned short check_Buff[MAX_BUFF_LEN]; //检验和缓冲区
    char tcp_send_data[1000];
	int read_data_len=0;

    BOOL flag; 
    int rect,nTimeOver;
    if(argc!= 5) 
    {
        printf("Usage: SendTcp soruce_ip source_port dest_ip dest_port \n"); 
        return false; 
    } 

	read_data_len=ReadData(tcp_send_data,1000);
	if(read_data_len<=0) return 1;

	
    if(WSAStartup(MAKEWORD(2,2), &WSAData)!=0) 
    { 
        printf("WSAStartup Error!\n"); 
        return false; 
    } 
	if((sock=WSASocket(AF_INET,SOCK_RAW,IPPROTO_RAW,NULL,0,
	WSA_FLAG_OVERLAPPED))==INVALID_SOCKET) 
    { 
        printf("Socket Setup Error!\n"); 
        return false; 
    } 
    flag=true; 
	if(setsockopt(sock,IPPROTO_IP,IP_HDRINCL,
		(char*)&flag,sizeof(flag))==SOCKET_ERROR) 
    { 
        printf("setsockopt IP_HDRINCL error!\n"); 
        return false; 
    } 
    nTimeOver=1000; 
	if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, 
		(char*)&nTimeOver, sizeof(nTimeOver))==SOCKET_ERROR) 
    { 
        printf("setsockopt SO_SNDTIMEO error!\n"); 
        return false; 
    } 

    //填充IP首部 
    ipHeader.h_verlen=(IPVER<<4 | sizeof(ipHeader)/sizeof(unsigned long)); 
    ipHeader.tos=(UCHAR)0; 
	ipHeader.total_len=htons((unsigned short)sizeof(ipHeader)+sizeof(tcpHeader)+read_data_len); 
    ipHeader.ident=0;       //16位标识
    ipHeader.frag_and_flags=0; //3位标志位
    ipHeader.ttl=128; //8位生存时间 
    ipHeader.proto=IPPROTO_TCP; //协议类型
    ipHeader.checksum=0; //检验和暂时为0
    ipHeader.sourceIP=inet_addr(argv[1]);  //32位源IP地址
    ipHeader.destIP=inet_addr(argv[3]);    //32位目的IP地址

    //计算IP头部检验和
    memset(check_Buff,0,MAX_BUFF_LEN);
    memcpy(check_Buff,&ipHeader,sizeof(IP_HEADER));
    ipHeader.checksum=checksum(check_Buff,sizeof(IP_HEADER));

    //构造TCP伪首部
    psdHeader.saddr=ipHeader.sourceIP;
    psdHeader.daddr=ipHeader.destIP;
    psdHeader.mbz=0;
    psdHeader.ptcl=ipHeader.proto;
    psdHeader.tcpl=htons(sizeof(TCP_HEADER)+read_data_len);

    //填充TCP首部 
    tcpHeader.th_dport=htons(atoi(argv[4])); //16位目的端口号
    tcpHeader.th_sport=htons(atoi(argv[2])); //16位源端口号 
    tcpHeader.th_seq=0;                      //SYN序列号
    tcpHeader.th_ack=0;                      //ACK序列号置为0
    //TCP长度和保留位
    tcpHeader.th_lenres=(sizeof(tcpHeader)/sizeof(unsigned long)<<4|0); 
	tcpHeader.th_flag=2; //修改这里来实现不同的标志位探测，2是SYN，1是//FIN，16是ACK探测 等等 
    tcpHeader.th_win=htons((unsigned short)16384);     //窗口大小
    tcpHeader.th_urp=0;                            //偏移大小    
    tcpHeader.th_sum=0;                            //检验和暂时填为0
    
    //计算TCP校验和 
    memset(check_Buff,0,MAX_BUFF_LEN);
    memcpy(check_Buff,&psdHeader,sizeof(psdHeader)); 
    memcpy(check_Buff+sizeof(psdHeader),&tcpHeader,sizeof(tcpHeader)); 
	memcpy(check_Buff+sizeof(PSD_HEADER)+sizeof(TCP_HEADER),
	tcp_send_data,read_data_len);
	tcpHeader.th_sum=checksum(check_Buff,sizeof(PSD_HEADER)+
	sizeof(TCP_HEADER)+read_data_len); 

    //填充发送缓冲区
    memset(Sendto_Buff,0,MAX_BUFF_LEN);
    memcpy(Sendto_Buff,&ipHeader,sizeof(IP_HEADER));
	memcpy(Sendto_Buff+sizeof(IP_HEADER),
		&tcpHeader,sizeof(TCP_HEADER));
	memcpy(Sendto_Buff+sizeof(IP_HEADER)+sizeof(TCP_HEADER),
		tcp_send_data,read_data_len);
	int datasize=sizeof(IP_HEADER)+sizeof(TCP_HEADER)+read_data_len;
    //发送数据报的目的地址
    SOCKADDR_IN dest;    
    memset(&dest,0,sizeof(dest));
    dest.sin_family=AF_INET; 
    dest.sin_addr.s_addr=inet_addr(argv[3]); 
    dest.sin_port=htons(atoi(argv[4]));

	rect=sendto(sock,Sendto_Buff,datasize, 0,
		(struct sockaddr*)&dest, sizeof(dest)); 
    if (rect==SOCKET_ERROR) 
    {  
		printf("send error!:%d\n",WSAGetLastError()); 
		return false; 
    } 
    else 
		printf("\nsend ok!\n");

    closesocket(sock); 
    WSACleanup(); 
    return 1; 
}
