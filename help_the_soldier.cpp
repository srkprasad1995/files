#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define pii pair<int ,int >

vector<pii > g(6);
int dp[7][1001];

int solve(int n,int T)
{
	if(T==0) return 0;
	if(n>6) return 0;
	if(dp[n-1][T] != -1) return dp[n-1][T];
	int& res  = dp[n-1][T];
	int sz = g[n-1].size();
	res = 0;
	for(int i=0;i<sz;i++)
	{
		if(T>=g[n-1][i].first)
			res = max(res,min(g[n-1][i].second,solve

int main()
{
	int n,T;
	scanf("%d %d",&n,&T);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[--a].pushback(pii(b,c));
	}
	int res=solve(0,T);
	printf("%d\n",res);
	return 0;
}
