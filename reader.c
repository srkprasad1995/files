#include<stdio.h>
#include<fcntl.h>
#include<string.h>

#define BUF 2000

int main(int argc,char *argv[])
{
	int fd;
	char buf[BUF+1] = {0};
	sscanf( argv[0],"%d",&fd);
	read(fd , buf,BUF);
	printf("process(%d) reads %s",getpid(),buf);
	return 0;
}
