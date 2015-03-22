#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void dfs(vector<int > a[],bool visited[],int i)
{
	visited[i] = true;
	for(int j=0;j<a[i].size();j++)
	{
		if(!visited[a[i][j]])
			dfs(a,visited,a[i][j]);
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int > a[10001];
	int k=m;
	while(m--)
	{
		int c,b;
		scanf("%d %d",&c,&b);
		c--;b--;
		a[c].push_back(b);
	}
	if( n != k+1)
	printf("NO\n");
	else{
	int cnt = 0;bool f=0;
	bool visited[10001] = {false};
	for(int i=0;i<n;i++)
	{
		if(!visited[i]) {
			cnt++;
			if(cnt>1){f=1;break;}
			dfs(a,visited,i);
		}
	}
	if(!f)
		printf("YES\n");
	else printf("NO\n");
	}
	return 0;
}
