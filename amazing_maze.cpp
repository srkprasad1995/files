#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<climits>

using namespace std;

#define pii pair<int ,int >
#define pip pair<int , pii>

#define inf  LONG_MAX

int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		char str[201][201];
		int a[201][201];
		for(int i=0;i<m;i++)
			scanf("%s",str[i]);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		long long time[201][201];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				time[i][j] = inf;
		priority_queue<pip , vector<pip> ,greater<pip> > Q;
		int su,sv,eu,ev;
		int visited[201][201] = {{0}};
		scanf("%d %d",&su,&sv);
		scanf("%d %d",&eu,&ev);
		time[su][sv] = 0;
		Q.push(pip(0,pii(su,sv)));
		while(!Q.empty())
		{
			int u=Q.top().second.first;
			int v = Q.top().second.second;
			int w= Q.top().first;
			Q.pop();
			if(u==eu && v==ev) break;
			visited[u][v] = true;
			for(int i=0;i<4;i++)
			{
				long long temp;
				int X = u+di[i];
				int Y = v+dj[i];
				if(X>=0 && X<m && Y>=0 && Y<n)
				{
					if(a[X][Y]-time[u][v] > 1 )
						temp =  a[X][Y];
					else temp = time[u][v] + 1;
					if(!visited[X][Y] && temp<time[X][Y])
					{
						time[X][Y] = temp;
						Q.push(pip(time[X][Y],pii(X,Y)));
					}
				}
			}
		}
		printf("%lld\n",time[eu][ev]);
	}
	return 0;
}
