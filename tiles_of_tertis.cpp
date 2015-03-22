#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	while(true)
	{
		long long n,m;
		scanf("%lld %lld",&n,&m);
		if(!n && !m) break;
		long long g = n>m ? gcd(n,m) : gcd(m,n);
		n /= g; m /=g;
		printf("%lld\n",n*m);
	}
	return 0;
}
