#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int dp[2001][2001];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int n;int v[2001];
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	int a=n-1;
	for(i=0;i<n;i++)
		dp[i][i] = v[i]*n;
	for(int l=2;l<=n;l++)
	{
		for(i = 0;i<n-l+1;i++)
		{
			j=i+l-1;
			dp[i][j]=max((dp[i][j-1]+v[j]*a),(dp[i+1][j]+v[i]*a));
		}
		a--;
	}
	printf("%d\n",dp[0][n-1]);
	return 0;
}
