#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BUF 2000

int main()
{
	char buf[BUF];
	char *data = "prasad is a good boy";
	int pipeends[2];
	int result;
	if(pipe(pipeends)==0)
	{
		result = fork();
		if(result == 0)
		{
			read(pipeends[1],buf,BUF);
			printf("process(%d) R -> %s\n",getpid(),buf);
		}
		printf("\nprocess(%d) T-> %s\n",getpid(),data);
		write(pipeends[1],data,strlen(data));
	}
	return 0;
}
