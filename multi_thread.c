#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int n;

void *sum_k(void *args)
{
	int i;int sum = 0;
	int *k = (int *) args;
	k[1] *= k[0];
	return NULL;
}

int main()
{
	pthread_t t1[6];
	int i;
	int k[2];
	k[1] = 1;k[0] = 1;
	for( i=0 ;i <6;i++)
	{
		k[0] = i+1;
		pthread_create(&t1[i] , NULL , sum_k ,(void *)k);
	}
	wait();
	printf("%d \n",k[1]);
	for(i=0 ; i<6; i++)
	pthread_join(t1[i],NULL);
	return 0;
}
