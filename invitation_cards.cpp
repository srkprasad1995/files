#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;


#define inf INT_MAX
#define pii pair<int,int>


vector<pii> a[1000001];

int dijik(vector<pii> a[],int s,int d,int n)
{
	int dist[1000001];
	for(int i=0;i<n;i++)
		dist[i] = inf;
	priority_queue<pii,vector<pii>,greater<pii> > Q;
	dist[s] = 0;
	Q.push(pii(0,s));
	bool visited[1000001]={false};
	while(!Q.empty())
	{
		int v = Q.top().second;
		int w = Q.top().first;
		Q.pop();
		visited[v]  = true;
		if(v==d) break;
		for(int i=0;i<a[v].size();i++)
		{
			if(!visited[a[v][i].second] &&dist[a[v][i].second] > w+a[v][i].first)
			{
				dist[a[v][i].second] = w+a[v][i].first;
				Q.push(pii(dist[a[v][i].second],a[v][i].second));
			}
		}
	}
	return dist[d];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		while(m--)
		{
			int b,d,c;
			b--;b--;
			scanf("%d %d %d",&b,&d,&c);
			a[b].push_back(pii(d,c));
		}
		int dist[1000001];
		for(int i=0;i<n;i++)
			dist[i] = inf;
		priority_queue<pii,vector<pii>,greater<pii> > Q;
		dist[0] = 0;
		Q.push(pii(0,0));
		bool visited[1000001]={false};
		while(!Q.empty())
		{
			int v = Q.top().second;
			int w = Q.top().first;
			Q.pop();
			visited[v]  = true;
			for(int i=0;i<a[v].size();i++)
			{
				if(!visited[a[v][i].second] &&dist[a[v][i].second] > w+a[v][i].first)
				{
					dist[a[v][i].second] = w+a[v][i].first;
					Q.push(pii(dist[a[v][i].second],a[v][i].second));
				}
			}
		}
		int res=0;
		for(int i=0;i<n;i++)
			res += dist[i];
		for(int i=1;i<n;i++)
			res += dijik(a,i,0,n);
		printf("%d\n",res);
		for(int i=0;i<n;i++)
			a[i].clear();
	}
	return 0;
}
