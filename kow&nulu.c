#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define pii pair<int ,int> 

int main()
{
	int ad[10][10][10][10] = {{{{0}}}};
	int i,j;
	int a,b;
	for(i = 0;i< 10;i++)
		for(j=0;j<10;j++)
		{
			printf("enter the adjacent nodes of %d,%d",i,j);
			while(1)
			{
				scanf("%d %d",&a,&b);
				if(a==-1 && b==-1) break;
				ad[i][j][a][b] = 1;
			}
		}
	int init[10][10]  = {{0}};
	int f[10][10] = {{0}};
	int red = 1;blue=2;black=3;
	printf("enter the final coordinates and colors 1:red 2:blue 3:black\n");
	while(1)
	{
		scanf("%d %d",&a,&b,&c);
		if(a == -1 && b==-1)
			break;
		f[a][b]  = c;
	}
	printf("enter the possible input positions\n");
	while(1)
	{
		scanf("%d %d",&a,&b);
		if(a == -1 && b==-1)
			break;
		init[a][b]  = c;
	}
	int u = 0,v=4;
	visitedf[10][10] = {{0}};
	bool f = 0;
	while(1)
	{	
		// if initial
		if(f==0)
		{
		visited[10][10] = {{0}};
		queue<int > Q;
		Q.push(pii(u,v));
		while(!Q.empty())
		{
			int p = Q.top().first;
			int q = Q.top().second;
			visited[p][q] = 1;
			if(f[p][q] == c){ 
				u = p;v=q;f=!f;
				break;} 
			for( i =0;i<10;i++)
				for(j=0;j<10;j++)
				{
					if(a[p][q][i][j] && !visited[i][j]) 
						Q.push(pii(i,j));
				}
		}
		}
		else 
		{
		visited[10][10] = {{0}};
		queue<int > Q;
		Q.push(pii(u,v));
		while(!Q.empty())
		{
			int p = Q.top().first;
			int q = Q.top().second;
			visited[p][q] = 1;
			if(init[p][q]){ 
				u = p;v=q;
				f=!f;visitedf[p][q] = 1;
				break;} 
			for( i =0;i<10;i++)
				for(j=0;j<10;j++)
				{
					if(a[p][q][i][j] && !visited[i][j]) 
						Q.push(pii(i,j));
				}
		}
		}		
	}
