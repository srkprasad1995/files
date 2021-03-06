#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>

using namespace std;

#define pii pair<int ,int >

int di[] = {0,0,-1,1};
int dj[] = {1,-1,0,0};
int a[251][251];
bool visited[251][251];
int c,m,n;

void dfs(int i,int j)
{
	visited[i][j] = true;
	c++;
	for(int k=0;k<4;k++)
	{
		int X = i+di[k];
		int Y = j+dj[k];
		if(X>=0 && X<n && Y>=0 && Y<m)
			if(!visited[X][Y] && a[X][Y] == 1)
				dfs(X,Y);
	}
	return ;
}

int main()
{
	while(true)
	{
		scanf("%d %d",&n,&m);
		if(!n && !m) break;
		map<int ,int> M;
		map<int ,int> :: iterator it;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		memset(visited,0,sizeof(visited));
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(!visited[i][j] && a[i][j]==1) 
				{
					c=0;
					dfs(i,j);
					cnt++;
					if((it =M.find(c))!= M.end())
						M[c]++;
					else M.insert(pii(c,1));
				}
		printf("%d\n",cnt);
		for(it = M.begin();it!=M.end();it++)
			printf("%d %d\n",it->first,it->second);
	}
	return 0;
}
