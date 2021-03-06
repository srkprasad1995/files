#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

#define inf 1000000000

int main()
{
	while(true)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		if(n==0 && m==0)
			break;
		int t[51][51],w[51][51];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&t[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&w[i][j]);
		int dp[53][1002];
		dp[0][0] = 0;
		for(int i=1;i<=n;i++)
			dp[i][0] = inf;
		int minT = -1;
		for(int k=1;k<=m;k++)
		{
			for(int i=0;i<n;i++)
			{
				dp[i][k] = dp[i][k-1];
				for(int j=0;j<n;j++)
				{
					if(k<t[j][i]) continue;
					dp[i][k] = min(dp[i][k],dp[j][k-t[j][i]]+w[j][i]);
				}
			}
			if(dp[n-1][k] != dp[n-1][k-1]) minT=k;
		}
		printf("%d %d\n",dp[n-1][minT],minT);
	}
	return 0;
}
