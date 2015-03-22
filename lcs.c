#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lcs(char [],char [],int ,int );

int main()
{
	char arr1[100],arr2[100];
	scanf("%s",arr1);
	scanf("%s",arr2);
	int n=strlen(arr1);
	int m=strlen(arr2);
	printf("%d",lcs(arr1,arr2,n,m));
	return 0;
}

int lcs(char arr1[],char arr2[],int n , int m)
{
	int l[100][100];
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				l[i][j]=0;
			else if(arr1[i-1] == arr2[j-1])
				l[i][j]=l[i-1][j-1]+1;
			else l[i][j]=l[i][j-1] > l[i-1][j] ? l[i][j-1] : l[i-1][j];
		}
	return l[n][m];
}
