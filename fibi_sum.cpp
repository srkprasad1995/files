#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

#define MOD 1000000007

using namespace std;

long long int solve(long long int n)
{
	long long int fib[2][2]={{1,1},{1,0}},res[2][2] = {{1,0},{0,1}},tmp[2][2]={{0,0},{0,0}};
	while(n)
	{
		if(n&1)
		{
			memset(tmp,0,sizeof(tmp));
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					for(int k=0;k<2;k++)
						tmp[i][j] = (tmp[i][j] + res[i][k]*fib[k][j])%MOD;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					res[i][j] = tmp[i][j];
		}
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					tmp[i][j] = (tmp[i][j] + fib[i][k]*fib[k][j])%MOD;
		for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					fib[i][j] = tmp[i][j];
		n=n/2;
	}
	return res[1][0];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,m;
		scanf("%lld %lld",&n,&m);
		int temp=(solve(m+2)-solve(n+1))%MOD;
		printf("%d\n",temp);
	}
	return 0;
}
