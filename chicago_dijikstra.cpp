#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define pif pair<int ,double>
#define pfi pair<double ,int >

int main()
{
	while(true)
	{
		int n,m;
		scanf("%d",&n);
		if(n==0) break;
		scanf("%d",&m);
		vector<pif > a[102];
		while(m--)
		{
			int p,q,cost;
			scanf("%d %d %d",&p,&q,&cost);
			double c = (double)cost/100.0;
			p--;q--;
			a[p].push_back(pif(q,c));
			a[q].push_back(pif(p,c));
		}
		priority_queue<pfi> Q;
		double dist[102];
		for(int i=0;i<n;i++)
			dist[i] = 0.0;
		dist[0] = 1.0;
		Q.push(pfi(1.0,0));
		bool visited[102] = {false};
		while(!Q.empty())
		{
			double w = Q.top().first;
			int v=Q.top().second;
			Q.pop();
			visited[v] = true;
			if(v == n-1) break;
			for(int i = 0;i<a[v].size();i++)
			{
				if(!visited[a[v][i].first] && dist[a[v][i].first]<w*a[v][i].second)
				{
					dist[a[v][i].first] = w*a[v][i].second;
					Q.push(pfi(dist[a[v][i].first],a[v][i].first));
				}
			}
		}
		printf("%.6lf percent\n",dist[n-1]*100.0);
	}
	return 0;
}			
