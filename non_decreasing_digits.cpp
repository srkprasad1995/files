#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

long long dp[66][10];

int main()
{
	for(int i=0;i<10;i++)
		dp[1][i] = 10-i;
	for(int i=2;i<65;i++)
		for(int j=0;j<10;j++)
			for(int k=j;k<10;k++)
			dp[i][j] += dp[i-1][k];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,n;
		scanf("%d %d",&k,&n);
		printf("%d %lld\n",k,dp[n][0]);
	}
	return 0;
}
