#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpr(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int x[100][2];
	int n=0,visited[100]={0};
	while(scanf("(%d,%d),",&x[n][0],&x[n][1])) n++;
	qsort(x,n,2*sizeof(int ),cmpr);
	int i=0,j;
	while(i<n)
	{
		int f=0,j=i+1;visited[i]=1;
		while((x[i][0]<=x[j][0]    &&   x[j][0]<=x[i][1] ) &&  j<n)
		{
			f=1;
			if(x[j][1]>x[i][1])
				x[i][1]=x[j][1];
			j++;
		}
		if(f==0)
			i++;
		else i=j;
	}
	for (j=0 ;j <n;j++)
	{
		if(visited[j])
			printf("[%d %d] ",x[j][0],x[j][1]);
	}
	return 0;
}


