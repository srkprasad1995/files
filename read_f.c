#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<string.h>
#include<unistd.h>
#define BUF 2000

int main()
{
	char name[100],buf[BUF+1];
	int fd;
	char data[100];
	printf("enter pipe name");
	scanf("%s",name);
	fd = open(name,O_RDONLY);
	printf("prasad\n");
	read(fd,buf,BUF);
	printf("process(%d) reads (%s)",getpid(),buf);
	return 0;
}
