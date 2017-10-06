#include <stdio.h> 
#include <string.h>
#include <winsock2.h> 
#include <ws2tcpip.h> 
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream.h>
#pragma comment(lib,"ws2_32.lib")

#define IPVER   4           //IPЭ��Ԥ��
#define MAX_BUFF_LEN 65500  //���ͻ��������ֵ

typedef struct ip_hdr    //����IP�ײ� 
{ 
	UCHAR h_verlen;            //4λ�ײ�����,4λIP�汾�� 
	UCHAR tos;                //8λ��������TOS 
	USHORT total_len;        //16λ�ܳ��ȣ��ֽڣ� 
	USHORT ident;            //16λ��ʶ 
	USHORT frag_and_flags;    //3λ��־λ 
	UCHAR ttl;                //8λ����ʱ�� TTL 
	UCHAR proto;            //8λЭ�� (TCP, UDP ������) 
	USHORT checksum;        //16λIP�ײ�У��� 
	ULONG sourceIP;            //32λԴIP��ַ 
	ULONG destIP;            //32λĿ��IP��ַ 
}IP_HEADER; 

typedef struct tsd_hdr //����TCPα�ײ� 
{ 
	ULONG saddr;    //Դ��ַ
	ULONG daddr;    //Ŀ�ĵ�ַ 
	UCHAR mbz;        //û��
	UCHAR ptcl;        //Э������ 
	USHORT tcpl;    //TCP���� 
}PSD_HEADER; 

typedef struct tcp_hdr //����TCP�ײ� 
{ 
	USHORT th_sport;            //16λԴ�˿� 
	USHORT th_dport;            //16λĿ�Ķ˿� 
	ULONG th_seq;                //32λ���к� 
	ULONG th_ack;                //32λȷ�Ϻ� 
	UCHAR th_lenres;            //4λ�ײ�����/6λ������ 
	UCHAR th_flag;                //6λ��־λ 
	USHORT th_win;                //16λ���ڴ�С 
	USHORT th_sum;                //16λУ��� 
	USHORT th_urp;                //16λ��������ƫ���� 
}TCP_HEADER; 

//CheckSum:����У��͵��Ӻ��� 
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

    char Sendto_Buff[MAX_BUFF_LEN];  //���ͻ�����
    unsigned short check_Buff[MAX_BUFF_LEN]; //����ͻ�����
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

    //���IP�ײ� 
    ipHeader.h_verlen=(IPVER<<4 | sizeof(ipHeader)/sizeof(unsigned long)); 
    ipHeader.tos=(UCHAR)0; 
	ipHeader.total_len=htons((unsigned short)sizeof(ipHeader)+sizeof(tcpHeader)+read_data_len); 
    ipHeader.ident=0;       //16λ��ʶ
    ipHeader.frag_and_flags=0; //3λ��־λ
    ipHeader.ttl=128; //8λ����ʱ�� 
    ipHeader.proto=IPPROTO_TCP; //Э������
    ipHeader.checksum=0; //�������ʱΪ0
    ipHeader.sourceIP=inet_addr(argv[1]);  //32λԴIP��ַ
    ipHeader.destIP=inet_addr(argv[3]);    //32λĿ��IP��ַ

    //����IPͷ�������
    memset(check_Buff,0,MAX_BUFF_LEN);
    memcpy(check_Buff,&ipHeader,sizeof(IP_HEADER));
    ipHeader.checksum=checksum(check_Buff,sizeof(IP_HEADER));

    //����TCPα�ײ�
    psdHeader.saddr=ipHeader.sourceIP;
    psdHeader.daddr=ipHeader.destIP;
    psdHeader.mbz=0;
    psdHeader.ptcl=ipHeader.proto;
    psdHeader.tcpl=htons(sizeof(TCP_HEADER)+read_data_len);

    //���TCP�ײ� 
    tcpHeader.th_dport=htons(atoi(argv[4])); //16λĿ�Ķ˿ں�
    tcpHeader.th_sport=htons(atoi(argv[2])); //16λԴ�˿ں� 
    tcpHeader.th_seq=0;                      //SYN���к�
    tcpHeader.th_ack=0;                      //ACK���к���Ϊ0
    //TCP���Ⱥͱ���λ
    tcpHeader.th_lenres=(sizeof(tcpHeader)/sizeof(unsigned long)<<4|0); 
	tcpHeader.th_flag=2; //�޸�������ʵ�ֲ�ͬ�ı�־λ̽�⣬2��SYN��1��//FIN��16��ACK̽�� �ȵ� 
    tcpHeader.th_win=htons((unsigned short)16384);     //���ڴ�С
    tcpHeader.th_urp=0;                            //ƫ�ƴ�С    
    tcpHeader.th_sum=0;                            //�������ʱ��Ϊ0
    
    //����TCPУ��� 
    memset(check_Buff,0,MAX_BUFF_LEN);
    memcpy(check_Buff,&psdHeader,sizeof(psdHeader)); 
    memcpy(check_Buff+sizeof(psdHeader),&tcpHeader,sizeof(tcpHeader)); 
	memcpy(check_Buff+sizeof(PSD_HEADER)+sizeof(TCP_HEADER),
	tcp_send_data,read_data_len);
	tcpHeader.th_sum=checksum(check_Buff,sizeof(PSD_HEADER)+
	sizeof(TCP_HEADER)+read_data_len); 

    //��䷢�ͻ�����
    memset(Sendto_Buff,0,MAX_BUFF_LEN);
    memcpy(Sendto_Buff,&ipHeader,sizeof(IP_HEADER));
	memcpy(Sendto_Buff+sizeof(IP_HEADER),
		&tcpHeader,sizeof(TCP_HEADER));
	memcpy(Sendto_Buff+sizeof(IP_HEADER)+sizeof(TCP_HEADER),
		tcp_send_data,read_data_len);
	int datasize=sizeof(IP_HEADER)+sizeof(TCP_HEADER)+read_data_len;
    //�������ݱ���Ŀ�ĵ�ַ
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
