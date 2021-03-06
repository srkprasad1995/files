#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int w[601],h[601];

int dp[601][601];
int n;

int solve(int W,int H)
{
	int &res=dp[W][H];
	if(res!=-1) return res;
	res = W*H;
	for(int i=0;i<n;i++)
	{
		if(H < h[i] || W < w[i]) continue;
		res = min(res,solve(W-w[i],H)+solve(w[i],H-h[i]));
		res = min(res,solve(W-w[i],h[i])+solve(W,H-h[i]));
	}
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int W,H;
		scanf("%d %d",&W,&H);
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&w[i],&h[i]);
		}
		printf("%d\n",solve(W,H));
	}
	return 0;
}
