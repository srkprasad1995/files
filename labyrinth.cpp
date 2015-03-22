#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<cstring>

using namespace std;

struct node {
int i,j;
}node;

int main()
{
	int t;
	scanf("%d",&t);
	while( t--)
	{
		char a[1001][1001],dist[1001][1001] = {0};
		int c,r;int max = 0;
		scanf("%d %d",&c,&r);
		for(int i=0;i<r;i++)
			scanf("%s",a[i]);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				if(a[i][j] == '.')
				{
					memset(dist,0,sizeof(dist));
					queue<struct node> q;
					int visited[1001][1001] = {0};
					struct node temp;temp.i = i;temp.j=j;
					dist[i][j] = 0;
					q.push(temp);
					int cnt = -1;
					while(!q.empty())
					{
						struct node n=q.front();
						q.pop();
						if(n.i>0 && a[n.i-1][n.j] == '.')
						{
							temp.i = n.i-1;temp.j=n.j;
							q.push(temp);
							dist[n.i-1][n.j]=dist[n.i][n.j]+1;
							if(dist[n.i-1][n.j] >max)
								max = dist[n.i-1][n.j];
						}
						if(n.i<(r-1) && a[n.i+1][n.j] =='.')
						{
							temp.i = n.i+1;temp.j=n.j;
							q.push(temp);
							dist[n.i+1][n.j]=dist[n.i][n.j]+1;
							if(dist[n.i+1][n.j] >max)
								max = dist[n.i+1][n.j];
						}
						if(n.j >0 && a[n.i][n.j-1] =='.'){
							temp.i = n.i;temp.j=n.j-1;
							q.push(temp);
							dist[n.i][n.j-1]=dist[n.i][n.j]+1;
							if(dist[n.i][n.j-1] >max)
								max = dist[n.i][n.j-1];
						}
						if(n.j < (c-1) && a[n.i][n.j+1] =='.')
						{
							temp.i = n.i;temp.j=n.j+1;
							q.push(temp);
							dist[n.i][n.j+1]=dist[n.i][n.j]+1;
							if(dist[n.i][n.j+1] >max)
								max = dist[n.i][n.j+1];
						}
					}
				}
			}
		printf("Maximum rope length is %d.\n",max);
	}
	return 0;
}
