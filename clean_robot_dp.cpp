#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;

#define pii pair<int ,int >

#define inf 10000001

int u,v;

int di[] = {0,0,-1,1};
int dj[] = {1,-1,0,0};

int a[21][21][21][21];
int main()
{
	while(true)
	{
		int n,m;
		scanf("%d %d",&m,&n);
		if(!n && !m) break;
		char str[21][21];
		pii final[21] ;
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(str[i][j] == 'o')
				{ u=i;v=j; }
				else if(str[i][j] == '*') final[cnt++] = pii(i,j);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int p=0;p<n;p++)
					for(int q=0;q<m;q++)
						a[i][j][p][q] = inf;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(str[i][j] == 'x') continue;
				a[i][j][i][j] =0;
				for(int k=0;k<4;k++)
				{
					int X = i+di[k];
					int Y= j+dj[k];
					if(X<n && X>=0 && Y<m && Y>=0)
						if(str[X][Y] != 'x')
							a[i][j][X][Y] = 1;
				}
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int p=0;p<n;p++)
					for(int q=0;q<m;q++)
						for(int x=0;x<n;x++)
							for(int y=0;y<m;y++)
								a[p][q][x][y] = min(a[p][q][x][y],a[p][q][i][j]+a[i][j][x][y]);
		bool visited[21] = {false};
		int s_index;
		int res=0;
		while(1)
		{
			bool f=1;
			int m=inf;
			for(int i=0;i<cnt;i++)
			{
				if(!visited[i] && m>a[u][v][final[i].first][final[i].second])
				{
					f=0;
					m=a[u][v][final[i].first][final[i].second];
					s_index = i;
				}
			}
			visited[s_index] = true;
			res += a[u][v][final[s_index].first][final[s_index].second];
			u = final[s_index].first; v=final[s_index].second;
			if(f) break;
		}
		if(res>=inf) printf("-1\n");
		else
		printf("%d\n",res);
	}
	return 0;
}
