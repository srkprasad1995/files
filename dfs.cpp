#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int dx = { 0 , 0 , -1 , 1};
int 

int max = 0;

void dfs( int x , int y ,int tot)
{
	if( !visited[x][y])
	{
		if(max < tol )
			max = tot;
		visited[x][y] = 1;
		
