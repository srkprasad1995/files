#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char str[300];
		scanf("%s",str);
		int dp[300][300]={{0}};
		int no_1[300][300]= {{0}};
		for(int i=0;i<n;i++)
		{
			dp[i][i] = (str[i] == '1');
			no_1[i][i] = dp[i][i];
		}
		for(int len  = 2;len<=n;len++)
		{
			for(int i=0;i<(n-len+1);i++)
			{
				int j=i+len-1;
				no_1[i][j] = no_1[i][j-1]+no_1[j][j];
				if(2*no_1[i][j] > (j-i+1))
					dp[i][j] = j-i+1;
				else
				for(int k = i;k<j;k++)
				{
					dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
		}
		printf("%d\n",dp[0][n-1]);
	}
	return 0;
}
