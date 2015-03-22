#include<stdio.h>
#include<stdlib.h>
#define R 3
#define C 3

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int minCost( int cost[R][C],int m,int n)
{
	int mc[R][C];
	mc[0][0]=cost[0][0];
	int i,j;
	for(i=1;i<=m;i++)
		mc[i][0]=mc[i-1][0] + cost[i][0];
	for(i=1;i<=n;i++)
		mc[0][i] = mc[0][i-1] + cost[0][i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			mc[i][j] = min (mc[i-1][j] ,mc[i][j-1] ,mc[i-1][j-1]) + cost[i][j];
	return mc[m][n];
}

int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", minCost(cost, 2, 2));
   return 0;
}
