#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

#define inf 1000000000

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,r;
		scanf("%d %d %d",&m,&n,&r);
		int t[101][101],w[101][101];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				t[i][j] = (i==j) ?0:inf ;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				w[i][j] = (i==j) ?0:inf ;
		while(r--)
		{
			int s,d,l,T;
			scanf("%d %d %d %d",&s,&d,&l,&T);
			s--;d--;
			w[s][d] = l;
			t[s][d] = T;
		}
			
		int dp[101][10002];
		dp[0][0] = 0;
		for(int i=1;i<=n;i++)
			dp[i][0] = inf;
		int minT = 0;
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
			if(dp[n-1][k] != dp[n-1][k-1]) minT = k;
		}
		if(dp[n-1][minT] == inf) printf("-1\n");
		else printf("%d\n",dp[n-1][minT]);
	}
	return 0;
}
