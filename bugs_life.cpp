#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<cstring>

using namespace std;

vector<int > graph[2001];
int color[2001];

void dfs(int i)
{
	int l=graph[i].size();
	for(int j=0;j<l;j++)
	{
		if(color[graph[i][j]] == -1)
		{
			color[graph[i][j]]=!color[i];
			dfs(graph[i][j]);
		}
	}
}

int main()
{
	int t,cnt=1;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		memset(color,-1,sizeof(color));
		for(int i=0;i<2001;i++)
			graph[i].clear();
		while(m--)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int f=1;
		for(int i=1;i<=n && f;i++)
		{
			if(color[i] == -1)
			{
				color[i] = 0;
				dfs(i);
			}
			for(int j=0;j<graph[i].size();j++)
			{
				if(color[i] == color[graph[i][j]])
				{
					f=0;
					break;
				}
			}
		}
		printf("Scenario #%d:\n",cnt++);
		if (f)
   			puts("No suspicious bugs found!");
		else
   			puts("Suspicious bugs found!");
	}
	return 0;
}
