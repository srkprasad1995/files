#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char name[100];
	int ret;
	printf("enter the fifo name");
	scanf("%s",name);
	ret  = mkfifo(name  , 0777);
	if(ret == 0)
		printf("success");
	else printf("error");
	return 0;
}
