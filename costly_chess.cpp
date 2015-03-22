#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

#define pii pair<int ,int>
#define pip pair<int,pii>
#define inf INT_MAX

int di[] = {1,-1,1,-1,2,-2,2,-2};
int dj[] = {2,-2,-2,2,1,-1,-1,1};

int dijik(pii s,pii e)
{
	int visited[9][9] = {{0}};
	priority_queue<pip,vector<pip> , greater<pip> >  Q;
	int dist[9][9];
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			dist[i][j] = inf;
	dist[s.first][s.second] = 0;
	Q.push(pip(0,s));
	while(!Q.empty())
	{
		int u=Q.top().second.first;
		int v = Q.top().second.second;
		int w = Q.top().first;
		visited[u][v] = true;
		if(Q.top().second == e) break;
		Q.pop();
		for(int i=0;i<8;i++)
		{
			int X=u+di[i];
			int Y = v+dj[i];
			if(X>=0 && X<8 && Y >=0 && Y<8)
			{
				if(!visited[X][Y] && dist[X][Y] > w+u*X+v*Y)
				{
					dist[X][Y] = dist[u][v]+u*X+v*Y;
					Q.push(pip(dist[X][Y],pii(X,Y)));
				}
			}
		}
	}
	return (dist[e.first][e.second]==INT_MAX ? -1:dist[e.first][e.second]);
}

int main()
{
	while(true)
	{
		pii s,e;int a,b,c,d;
		if(scanf("%d",&a) == EOF) break;
		scanf("%d %d %d",&b,&c,&d);
		s.first = a;
		s.second = b;
		e.first= c;
		e.second = d;
		printf("%d\n",dijik(s,e));
	}
	return 0;
}
