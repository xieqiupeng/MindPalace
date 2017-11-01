#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <asm/ioctls.h>
#include <stropts.h>
#include <dirent.h>




void GetFile();
void LogError(char * cContent);
bool Dencrypt(char * filename);


#define g_Dencrypt_Path "/home/dencrypt/origin/"
#define g_After_Dencrypt_Path "/home/dencrypt/after/"
#define g_ERR_PATH "/home/encrypt/log/"
int nKey = 3;

int main() 
{ 
	
		
	GetFile();
	
	
	return 0;	
} 



void GetFile()
{
  DIR *dirptr;
  struct dirent *entry;
  if( (dirptr = opendir(g_Dencrypt_Path)) == NULL) 
  {
  	char temp[100];
	 	sprintf(temp,"�򿪼���·��ʧ��.\n%s",g_Dencrypt_Path);
  	LogError(temp);
    return;
  }
  printf("������·�����Ƿ����µ��ļ�....\n");
  
  while(entry = readdir(dirptr))
	{	
	  	int moveLen = strlen(entry->d_name)- 4;
	  	//�����txt�ļ�
	    if (memcmp(entry->d_name+moveLen, ".txt", 4)==0)
	    {
	    	char AllPath[256];
	    	strcpy(AllPath,g_Dencrypt_Path);
	    	strcat(AllPath,entry->d_name);
	    	printf("��鵽�µ�txt�ļ�,�ļ���:%s.\n",entry->d_name);
	    	
	    	//����
	    	if(Dencrypt(entry->d_name))
				{
					
					printf("�����ļ��ɹ����ļ���:%s.\n",entry->d_name);
							
				}
				else
				{
					printf(" �����ļ�ʧ�ܣ��ļ���:%s.\n",entry->d_name);
					
		    }
	    }
	    else
	    {
	    	printf("û��Ҫ���ܵ��ļ�.\n");
	    }
	     
	}
	 closedir(dirptr);
	 return;
 
}








bool Dencrypt(char * filename)
{
	char oldpath[256];
	strcpy(oldpath,g_Dencrypt_Path);
	strcat(oldpath,filename);
	
	char newpath[256];
	strcpy(newpath,g_After_Dencrypt_Path);
	strcat(newpath,filename);
	
  
	FILE * m_fp = fopen(oldpath, "r+");
	if(m_fp == NULL)
	{
		char cTemp[500];
		sprintf(cTemp,"���ļ�ʧ��:%s.����ԭ��:%s\n", oldpath,strerror(errno));
		LogError(cTemp);
		return false;
	}
	//printf("���ļ��ɹ����ļ�·��:%s\n", oldpath);
	
			
	
	struct stat file;
	if(stat(oldpath, &file) !=0)
	{
		char temp[500];
		sprintf(temp,"����ļ���Сʧ��.����ԭ��:%s\n",strerror(errno));
		LogError(temp);
		fclose(m_fp);
		return false;
	}
	
	
	unsigned long long llfilesize = file.st_size;
	printf("�ļ�size��%qd.\n",llfilesize);
	
	
	char * pReadBuff ;
	pReadBuff = new char[llfilesize];
	
	
				
	if(fseeko(m_fp, 0, SEEK_SET) != 0)
	{
		char cTemp[300];
		sprintf(cTemp,"��ȡ�ļ�ʧ��seek,�ļ�·��:%s,���ݿ��С:%qd.����ԭ��%s.\n",filename,llfilesize,strerror(errno));
		LogError(cTemp);
		fclose(m_fp);
		return false;
	}
	
 fread(pReadBuff, 1, llfilesize,m_fp);
	
	 
 	char * pBuf = new char [llfilesize];
  char * pFinish = new char[llfilesize];
		

	FILE * m_fp_new = fopen(newpath, "a+");
	if(m_fp_new == NULL)
	{
		char cTemp[500];
		sprintf(cTemp,"���ļ�ʧ��:%s.����ԭ��:%s\n", newpath,strerror(errno));
		LogError(cTemp);
		return false;
	}
	//printf("���ļ��ɹ����ļ�·��:%s\n", newpath);
 
 for (int i=0;i<llfilesize;i++)
	{		
		pBuf[i] = pReadBuff[i];
		if (pBuf[i]<nKey)
		{
			pBuf[i]=pBuf[i]+256-nKey;
		}
		else
		{
			pBuf[i]=pBuf[i]-nKey;
		}
		pFinish[i] = pBuf[i];
		fputc(pFinish[i],m_fp_new);
		

	}

	return true;

	
}
	

void LogError(char * cContent)
{
	FILE *fpErr;
	char cFileName[256];
	char cOutBuf[256];

	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	sprintf(cFileName, "%sFailLog[%d-%2d-%2d].txt", g_ERR_PATH, (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);

	fpErr = fopen(cFileName,"a+");
	if(fpErr == NULL)
	{
		printf("��¼������־ʱ���ļ�ʧ��:%s\n", cFileName);
		return;
	}
	
	sprintf(cOutBuf, "[%d-%02d-%02d %02d:%02d:%02d] ", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday, p->tm_hour+8, p->tm_min, p->tm_sec);
	strcat(cOutBuf,cContent);
	
	printf("%s",cContent);
	if(fputs(cOutBuf, fpErr) == EOF)
	{
		printf("��¼������־ʱд�ļ�ʧ��\n");
		fclose(fpErr);
		return;
	}
	fclose(fpErr);	
	return;
}
