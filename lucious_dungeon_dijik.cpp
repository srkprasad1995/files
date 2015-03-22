#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

#define inf INT_MAX
#define pii pair<int ,int>
#define pip pair<int,pii>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int a[101][101];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		int dist[101][101];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				dist[i][j] = inf;
		int p,q;
		int T;
		bool visited[101][101] = {false};
		scanf("%d %d %d",&p,&q,&T);
		p--;q--;
		priority_queue< pip , vector<pip>, greater <pip> >  Q;
		dist[0][0] = a[0][0];
		Q.push(pip(dist[0][0],pii(0,0)));
		while(!Q.empty())
		{
			int i=Q.top().second.first;
			int j = Q.top().second.second;
			int w = Q.top().first;
			Q.pop();
			visited[i][j]  = true;
			if(i==p && j==q) break;
			if(j+1<m && !visited[i][j+1] && dist[i][j+1]>w+a[i][j+1])
			{
				dist[i][j+1] = w+ a[i][j+1];
				Q.push(pip(dist[i][j+1],pii(i,j+1)));
			}
			if(j-1>=0 && !visited[i][j-1] && dist[i][j-1]>w+a[i][j-1])
			{
				dist[i][j-1] = w+ a[i][j-1];
				Q.push(pip(dist[i][j-1],pii(i,j-1)));
			}
			if(i+1<n && !visited[i+1][j] && dist[i+1][j]>w+a[i+1][j])
			{
				dist[i+1][j] = w+ a[i+1][j];
				Q.push(pip(dist[i+1][j],pii(i+1,j)));
			}
			if(i-1>=0 && !visited[i-1][j] && dist[i-1][j]>w+a[i-1][j])
			{
				dist[i-1][j] = w+ a[i-1][j];
				Q.push(pip(dist[i-1][j],pii(i-1,j)));
			}
		}
		if(T>= dist[p][q])
		{
			printf("YES\n%d\n",T-dist[p][q]);
		}
		else printf("NO\n");
	}
	return 0;
}
