#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;


long long sum(long long N)
{
	if(!(N/10)) return (N*(N+1))/2;
	int i=0;
	long long n=N;
	while((n/10 )>0)
	{
		i++;
		n /= 10;
	}
	long long p = pow(10,i);
	return ((n*45*i*p/10)+ n*(n-1)*p/2+ n*(N%p+1) + sum(N%p));
}

int main()
{
	while(true)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		if(a==-1 && b==-1) break;
		long long res = sum(b) - sum(a-1);
		printf("%lld\n",res);
	}
	return 0;
}
