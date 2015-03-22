#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int f[100001];

void dfs(vector<int > g[],int i)
{
	if(!f[i])
	{
		f[i] = 1;
		int sz=g[i].size();
		for(int j=0;j<sz;j++)
		{
			int k=g[i][j];
			if(!f[k])
				dfs(g,k);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		vector<int > g[100001];
		memset(f,0,sizeof(f));
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int cnt = 0;
		for(int i = 1;i<=n;i++)
		{
			if(!f[i])
			{
				cnt++;
				dfs(g,i);
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
