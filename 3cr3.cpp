#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>

using namespace std;

long long s[1000001],k[1000001];
long long sum[1000001];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) sum[i] = -1;
		for(int i=0;i<n;i++)
			scanf("%lld",&s[i]);
		for(int i=0;i<n;i++)
			scanf("%lld",&k[i]);
		sum[n-1] = s[n-1];
		for(int i=n-2;i>=0;i--)
		{
			if((i+k[i])<n && sum[i+k[i]]!=-1)
				sum[i] = sum[i+k[i]]+s[i];
			if((i+k[i]+1)<n && sum[i+k[i]+1]!=-1)
				sum[i] =max(sum[i],sum[i+k[i]+1]+s[i]);
			if((i+k[i]+2)<n && sum[i+k[i]+2]!=-1)
				sum[i] = max(sum[i],sum[i+k[i]+2]+s[i]);
		}
		printf("%lld\n",sum[0]);
	}
	return 0;
}
