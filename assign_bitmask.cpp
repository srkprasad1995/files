#include<cstdio>
#include<iostream>
#include<bitset>
#include<cstdlib>

using namespace std;

long long dp[1<<20];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[21][21];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		int m = 1<<n;
		for(int i=0;i<m;i++)
			dp[i] = 0;
		dp[0] = 1;
		for(int i=0;i<m-1;i++)
		{
			int k=__builtin_popcount(i);
			for(int j=0;j<n;j++)
			{
				if(a[k][j] && !(i&(1<<j)))
					dp[i | (1<<j)] += dp[i];
			}
		}
		printf("%lld\n",dp[m-1]);
	}
	return 0;
}
