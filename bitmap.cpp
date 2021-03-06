#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdlib>

using namespace std;

typedef struct node{
	int r,c,d;
	node( int _r,int _c,int _d)
	{
		r=_r;
		c=_c;
		d=_d;
	}
}node;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc --)
	{
		int r,c,ans[183][183];
		bool visited[183][183];
		char M[183][183];
		int n,m;
		queue<node> que;
		int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			fill(visited[i],visited[i]+m,false);
			scanf("%s",M[i]);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(M[i][j] == '1'){
					que.push(node(i,j,0));
					visited[i][j] = true;
					ans[i][j] = 0;
				}
			}
		while(!que.empty())
		{
			node p=que.front();
			que.pop();
			for(int i = 0;i<4;i++){
				r=p.r+dr[i];
				c=p.c+dc[i];
				if(r>=0 && r<n && c>=0 && c<m && !visited[r][c])
				{
					ans[r][c] = p.d+1;
					que.push(node(r,c,p.d+1));
					visited[r][c]=true;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d",ans[i][j]);
				if( j == m-1) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
