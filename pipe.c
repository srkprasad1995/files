#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define size 20000

int main()
{
	FILE *fp;
	char BUF[size +1];
	strcpy(BUF,"HELLO\n");
	fp  = popen("wc","w");
	fwrite(BUF,sizeof(char),strlen(BUF),fp);
	printf(":process (%d) Rx->%s\n",getpid(),BUF);
	pclose(fp);
	return 0;
}
