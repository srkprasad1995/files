#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int > a[],bool visited[],int i)
{
	visited[i] = true;
	for(int j=0;j<a[i].size();j++)
	{
		if(!visited[a[i][j]])
			dfs(a,visited,a[i][j]);
	}
	return ;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c,b,e;
		scanf("%d %d",&n,&e);
		vector<int > a[100001];
		bool visited[100001] = {false};
		while(e--)
		{
			scanf("%d %d",&c,&b);
			a[c].push_back(b);
			a[b].push_back(c);
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
			{
				dfs(a,visited,i);
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
