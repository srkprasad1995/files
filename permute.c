#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void permute(char [],int ,int );
void swap(char *,char *);

int main()
{
	char str[20];
	scanf("%s",str);
	permute(str,0,strlen(str)-1);
	return 0;
}

void permute(char a[],int i , int n)
{
	if(i==n)
	{
		printf("%s\n",a);
		return ;
	}
	int j;
	for(j=i;j<=n;j++)
	{
		swap(a+i,a+j);
		permute(a,i+1,n);
		swap(a+i,a+j);
	}
	return ;
}

void swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a=*b;
	*b=temp;
}
