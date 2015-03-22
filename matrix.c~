#include <stdio.h>
#include <pthread.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include<limits.h>
#define N 1000

int m1[N][N] , m2[N][N] , res_mat[N][N];

int temp[1001];
void *matrixmultiplication(void *a)
{
	int k ,j;
	int *i = (int *)a;
	for( j = 0; j < N; j++ ) {
		res_mat[*i][j] = 0;
		for(k = 0 ;k < N ;k++)
			res_mat[*i][j] += m1[*i][k] * m2[k][j];
	}
}
pthread_t tid[1005];
int main()
{
	clock_t time;
	time = clock();
	int i,j,k;
	FILE *fp;
	fp = fopen("input.txt", "r");
	int cnt = 0; 
	for(i = 0; i < N ;i++)
	{
		for(j = 0 ; j < N ;j++)
			fscanf(fp, "%d", &m1[i][j] );
	}
	for(i = 0; i < N ;i++)
	{
		for(j = 0 ; j < N ;j++)
			fscanf(fp, "%d", &m2[i][j] );
	}
	printf("input taken\n");
	for(i = 0 ;i < N ;i++)
	{
		temp[cnt] = i;
		pthread_create(&tid[cnt] ,NULL , matrixmultiplication, (void *)(&temp[cnt++]));
	}
	printf("threads are created\n");
	for(i = 0 ;i < cnt ;i++)
		pthread_join(tid[i] , NULL);
	printf("threads joined\n");
	time = clock() - time;
	printf("the net time taken in seconds is  %f\n",(float)time/CLOCKS_PER_SEC);
	return 0;
}
