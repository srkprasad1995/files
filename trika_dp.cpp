#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int x,y;
	scanf("%d %d",&x,&y);
	x--;y--;
	int a[21][21];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	int dp[21][21]={{0}};
	int res = a[x][y];
	for(int i=m-2;i>=0;i--)
		a[n-1][i] += a[n-1][i+1];
	for(int j=n-2;j>=x;j--)
		a[j][m-1] += a[j+1][m-1];
	for(int i=n-2;i>=x;i--)
		for(int j=m-2;j>=0;j--)
			a[i][j] = min(a[i][j] + a[i][j+1],a[i][j] + a[i+1][j]);
	res  = 2*res - a[x][y];
/*	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
*/	//}
	if(res<0)
		printf("N");
	else printf("Y %d",res);
	return 0;
}
		
