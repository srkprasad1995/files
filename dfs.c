#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

void printMin(int a[100][100] , int ,int);
void util(int a[100][100] ,int ,int ,int ,int ,int);
int util1(int a[100][100] ,int ,int ,int ,int ,int);

int cnt=0,min=INT_MAX,visited[100][100]={{0}};

int main()
{
	int i,j,a[100][100];
	int n,m;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	printMin(a,n,m);
	return 0;
}

void printMin(int a[100][100] , int n , int m)
{
	int i,j;
	util( a , n , m , 0 , 0 , 0 );
	util1( a,n,m,0,0,0);
	for(i=0 ;i<n ;i++)
	{
		for(j=0; j<m ;j++)
			if(a[i][j] == 2)
				printf("x  ");
			else printf("%d  ",a[i][j]);
		printf("\n");
	}
	printf(" \n%d\n " , min);
	return ;
}

void util(int a[100][100] , int n ,int m,int i, int j,int len)
{
	if(i == n-1  && j== m-1 && min > len)
		min=len;
	else 
	{
		visited[i][j]==1;
		if( (i+1) >=0 && (i+1)<n && !visited[i+1][j] && a[i+1][j])
			util(a , n ,m , i+1 ,j,len+1);
		if( (j+1)>=0 && (j+1)<m && !visited[i][j+1] && a[i][j+1])
			util(a , n ,m , i ,j+1,len +1);
		if( (i+1) >=0 && (i+1)<n && (j+1)>=0 && (j+1)<m && !visited[i+1][j+1] && a[i+1][j+1])
			util( a, n , m , i+1  , j+1 , len+1);
		visited[i][j] = 0;
	}
	return ;
}

int util1(int a[100][100] , int n ,int m,int i, int j,int len)
{
	if(i == n-1  && j== m-1 && min == len)
	{
		a[i][j] = 2;
		return 1;
	}
	else 
	{
		visited[i][j]==1;
		if( (i+1) >=0 && (i+1)<n && !visited[i+1][j] && a[i+1][j])
			if(util1(a , n ,m , i+1 ,j,len+1))
			{
				a[i][j] = 2;
				visited[i][j] = 0;
				return 1;
			}
		if( (j+1)>=0 && (j+1)<m && !visited[i][j+1] && a[i][j+1])
			if(util1(a , n ,m , i ,j+1,len +1))
			{
				a[i][j] = 2;
				visited[i][j] = 0;
				return 1;
			}
		if( (i+1) >=0 && (i+1)<n && (j+1)>=0 && (j+1)<m && !visited[i+1][j+1] && a[i+1][j+1])
			if(util1( a, n , m , i+1  , j+1 , len+1))
			{
				a[i][j] = 2;
				visited[i][j] = 0;
				return 1;
			}
		visited[i][j] = 0;
	}
	return 0 ;
}
