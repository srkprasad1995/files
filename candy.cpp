#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int my_fun(int a,int b)
{
	return a>b;
}

int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		long long c[100001],p[100001];
		long long sum=0;
		for(int i=0;i<n;i++)
			scanf("%lld",&c[i]);
		for(int i=0;i<n;i++)
			scanf("%lld",&p[i]);
		sort(c,c+n);
		sort(p,p+n,my_fun);
		for(int i=0;i<n;i++)
			sum += c[i]*p[i];
		printf("%lld\n",sum);
	}
	return 0;
}
