#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	const char *p[] = {"ls","-l","temp.c",(char *)0};
	execv("/bin/ls", (const char*)p);
	//char *cmd[] = {"whoami",(char*)0};
        //return execv("/usr/bin/",cmd); 
	return 0;
}
