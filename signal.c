#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void fun(int sig)
{
	printf(" signal catched %d\n",sig);
	signal(SIGINT,SIG_DFL);
	while(1){
		printf("can cac \n");
		sleep(1);
	}
}

int main()
{
	signal( SIGINT , fun);
	while(1)
	{
		printf(" im sleeping\n");
		sleep(1);
	}
	return 0;
}
