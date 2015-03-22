#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<limits.h>

using namespace std;

int main()
{
	int n;
	while((scanf("%d",&n))!= EOF)
	{
		int color[101][101]={{ 0 }}, dp[101][101] = {{0}};
		for(int i=0 ;i < n ;i ++)
		{
			scanf("%d", &color[i][i]);
			dp[i][i] = 0;
		}
		int len;
		for(len = 2 ; len <= n ;len ++)
		{
			for(int i = 0 ;i <= n-len ; i++)
			{
				int j=i+len-1;
				dp[i][j] = INT_MAX;
				for(int k = i ; k < j ;k++)
				{
					int temp = dp[i][k] + dp[k+1][j] + color[i][k]*color[k+1][j];
					if(temp < dp[i][j])
					{
						dp[i][j] =temp;
						color[i][j] = (color[i][k] + color[k+1][j])%100;
					}
				}
			}
		}
		printf("%d\n",dp[0][n-1]);
	}
	return 0;
}
