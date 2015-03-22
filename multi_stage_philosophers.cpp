#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int a[101][101],dp[101][101];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		for(int j=0;j<m;j++)
			dp[n-1][j] = a[n-1][j];
		for(int i=n-2;i>=0;i--)
			for(int j=0;j<m;j++)
			{
				dp[i][j] = dp[i+1][j];
				if((j+1)<m) dp[i][j] = dp[i][j] < dp[i+1][j+1] ? dp[i+1][j+1]:dp[i][j];
				if((j-1)>=0) dp[i][j] = dp[i][j] < dp[i+1][j-1] ? dp[i+1][j-1]:dp[i][j];
				dp[i][j] += a[i][j];
			}
		int max = a[0][0];
		for(int j=1;j<m;j++)
			max = max>dp[0][j] ? max:dp[0][j];
		printf("%d\n",max);
	}
	return 0;
}
