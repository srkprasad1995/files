#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>

using namespace std;

int n,m;
char str[21][21];
int visited[21][21];

int di[] = {0,0,-1,1};
int dj[] = {1,-1,0,0};

void dfs(int su,int sv)
{
	visited[su][sv] = true;
	for(int i=0;i<4;i++)
	{
		int X=su+di[i];
		int Y = sv+dj[i];
		if(X<n && X>=0 && Y>=0 && Y<m)
			if(!visited[X][Y] && str[X][Y] != '#')
				dfs(X,Y);
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
		int su,sv,eu,ev;
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);
		int cnt = 0;
		memset(visited,0,sizeof(visited));
		bool vis[21][21] = {{0}};
		for(int i=0;i<n;i++)
		{
			if(str[i][m-1] =='.' && !vis[i][m-1])
			{
				if(cnt == 1) eu = i,ev=m-1;
				else su=i,sv=m-1;
				 cnt++;
			}
			vis[i][m-1] = true;
			if(str[i][0] == '.' && !vis[i][0]) 
			{
				if(cnt == 1) eu = i,ev=0;
				else su=i,sv=0;
				 cnt++;
			}
			vis[i][0] = true;
		}
		for(int i=0;i<m;i++)
		{
			if(str[0][i] =='.' && !vis[0][i]) 
			{
				if(cnt == 1) eu = 0,ev=i;
				else su=0,sv=i;
				 cnt++;
			}
			vis[0][i] = true;
			if(str[n-1][i] =='.' && !vis[n-1][i]) 
			{
				if(cnt == 1) eu = n-1,ev=i;
				else su=n-1,sv=i;
				 cnt++;
			}
			vis[n-1][i] = true;
		}
		if(cnt != 2)
		{
			printf("invalid\n");
			continue;
		}
		dfs(su,sv);
		if(visited[eu][ev]) printf("valid\n");
		else printf("invalid\n");
	}
	return 0;
}
