#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid;
	pid=fork();
	printf("%d -> %d\n",pid,getpid());
	if(pid==0)
		printf("child process\n");
	else if(pid>0){
		printf("parent process\n");
	}
	else printf("fork failed\n");
	return 0;
}
