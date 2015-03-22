#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,k,t,f;
		scanf("%lld %lld %lld %lld",&n,&k,&t,&f);
		long long sum;
		sum = (f - n) / (k-1);
		sum *= k;
		sum += n;
		printf("%lld\n",sum);
	}
	return 0;
}
