#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>

using namespace std;

#define pii pair<int ,int>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		char a[50][50];
		int dist[50][50]={{0}};
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int visited[50][50] = {{0}};
		queue<pii > Q;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j] == 'A')
				{
					visited[i][j] = 1;
					dist[i][i] = 1;
					Q.push(pii(i,j));
				}
		int di[] ={-1,0,1};
		int dj[]={-1,0,1};
		int max =0;
		while(!Q.empty())
		{
			int p=Q.front().first;
			int q=Q.front().second;
			Q.pop();
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(!visited[p+di[i]][q+dj[j]] && (a[p][q] ==(a[p+di[i]][q+dj[j]]-1)) && (p+di[i])>=0&&(p+di[i])<n&&(q+dj[j])>=0&&(q+dj[j])<m)
					{
						visited[p+di[i]][q+dj[j]] = 1;
						dist[p+di[i]][q+dj[j]] = dist[p][q] + 1;
						Q.push(pii(p+di[i],q+dj[j]));
					}
			if(max<dist[p][q])
				max = dist[p][q];
		}
		printf("%d\n",max);			
	}
	return 0;
}
