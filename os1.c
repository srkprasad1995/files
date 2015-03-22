#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	execl("/bin/sh","sh","test.sh",NULL);
	return 0;
}
