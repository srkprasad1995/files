#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[20][20],b[20][20];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			b[i][j]=a[i][j]=i*n+j+1;
	
	for(int i=1;i<=n;i++)
	{
		int visited[4000]={0};
		for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
			a[x][y] = b[x][y];
		for(int j=0;j<i;j++)
		{
			int k=rand()%(n*n);
			while(visited[k]) k=rand()%(n*n);
			visited[k]=1;
			int p=k/n;
			int q=k%n;
			a[p][q]=0;
		}
		for(int x=0;x<n;x++){
		for(int y=0;y<n;y++)
			printf("%d ",a[x][y]);
			printf("\n");}
		printf("\n ----------\n");
	}
	return 0;
}
