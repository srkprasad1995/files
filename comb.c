#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[50];
char str[10];
int visited[100];

int cmpr(const void *a,const void *b)
{
	return *(char *)a-*(char *)b;
}

void back(int s,int n,int index)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!visited[i]){
		visited[i]=1;
		a[index]=i;int j;
		for(j=0;j<=index;j++)
			printf("%c",str[a[j]]);
		printf("\n");
		back(i,n,index+1);
		visited[i]=0;}
	}
}
int main()
{
	scanf("%s",str);
	int n=strlen(str);
	qsort(str,n,sizeof(char),cmpr);
	back(-1,n,0);
	return 0;
}

