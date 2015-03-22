#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int x;
	scanf("%d",&x);
	int n;
	scanf("%d",&n);
	int a[10001];
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		a[i] = ((i>0)?a[i-1]:0)+k;
	}
	bool dp[100003] = {0};
	dp[0] = 1;
	for(int i=0;i<x;i++)
		for(int j=0;j<n;j++)
			if(dp[i] && (i+a[j])<=x)
				dp[i+a[j]] = 1;
	if(dp[x])
		printf("YES\n");
	else printf("NO\n");
	return 0;
}
