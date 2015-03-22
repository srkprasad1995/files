#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int a[101][101];
int n;
int di[] = {1 ,-1 ,0 ,0 };
int dj[] = {0,0 ,-1 ,1 };

bool visited[101][101];

void dfs(int i, int j)
{
	visited[i][j] = true;
	for(int k=0;k<4;k++)
	{
		int X = i+di[k];
		int Y = j+dj[k];
		if(X<n && X>=0 && Y>=0 && Y<n)
			if(!visited[X][Y] && a[i][j] == a[X][Y])
				dfs(X,Y);
	}
	return ;
}
	

int main()
{
	while(true)
	{
		scanf("%d",&n);
		if(!n) break;
		memset(visited,0,sizeof(visited));	
		memset(a,0,sizeof(a));
		for(int i=1;i<n;i++)
		{
			int c,b;
			while(true)
			{
				scanf("%d %d",&c,&b);
				c--;b--;
				a[c][b] = i;
				char c = getc(stdin);
				if(c=='\n') break;
				else ungetc(c,stdin);
			}
			dfs(c,b);
		}
		int flag = 1;
		for(int i=0;i<n && flag ;i++)
			for(int j=0;j<n&& flag ;j++)
				if(a[i][j] == 0)
				{
					dfs(i,j);
					flag=0;
				}
		bool f=false;
		for(int i=0;i<n&&!f;i++)
			for(int j=0;j<n&&!f;j++)
				if(!visited[i][j])
					f=1;
		if(f) printf("wrong\n");
		else printf("good\n");
	}
	return 0;
}
