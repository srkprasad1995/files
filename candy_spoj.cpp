#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

long long max_sum(long long a[],int n)
{
	if(n==0) return 0;
	long long excl = 0;
	long long incl = a[0];
	int i=1;
	while((i)<n)
	{
		long long ex = max(incl,excl);
		incl = excl + a[i++];
		excl = ex;
	}
	return max(incl,excl);
}


int main()
{
	while(true)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		if(!n&&!m) break;
		long long a[100002],b[100002];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				scanf("%lld",&b[j]);
			a[i] = max_sum(b,m);
		}
		long long res = max_sum(a,n);
		printf("%lld\n",res);
	}
	return 0;
}
