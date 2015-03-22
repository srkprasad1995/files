#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>

using namespace std;

int a[101][101];
int b[101][101];
int visited[101][101];
int n,m;

#define mx 100001
int di[] = { 0 ,0,-1,1};
int dj[] = {1,-1,0,0};

void dfs(int i,int j,int h)
{
	visited[i][j] = 1;
	b[i][j] = a[i][j];
	for(int k=0;k<4;k++)
	{
		int X= i+di[k];
		int Y = j+dj[k];
		if(X<n&&X>=0&&Y<m && Y>=0)
			if(!visited[X][Y] && a[X][Y] >=h)
				dfs(X,Y,a[X][Y]);
	}
	return ;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				b[i][j] = mx;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++)
		{
			if(!visited[i][0])
				dfs(i,0,a[i][0]);
			if(!visited[i][m-1])
				dfs(i,m-1,a[i][m-1]);
		}
		for(int i=0;i<m;i++)
		{
			if(!visited[0][i])
				dfs(0,i,a[0][i]);
			if(!visited[n-1][i])
				dfs(n-1,i,a[n-1][i]);
		}
		while(1)
		{
			bool f=1;
			for(int i=1;i<n-1;i++)
			{
				for(int j=1;j<m-1;j++)
				{
					if(!visited[i][j])
					{
						int m=mx;
						for(int k=0;k<4;k++)
						{
							int X=i+di[k];
							int Y=j+dj[k];
							if(X<n && X>=0 && Y<m && Y>=0)
								m=min(m,max(b[X][Y],a[X][Y]));
						}						
						if(m<b[i][j])
						{
							b[i][j] = m;
							f=0;
						}
					}
				}
			}
			if(f) break;
		}
		int res = 0;
		for(int i=1;i<n-1;i++)
			for(int j=1;j<m-1;j++)
				if(b[i][j] > a[i][j])
				res += b[i][j] - a[i][j];
		printf("%d\n",res);
	}
	return 0;
}
