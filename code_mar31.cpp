#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		n = n-m;
		int a = 1,r=2,d=1;
		double k = a/(1-r);
		k += d*r*(1 - pow(r,n-1))/((1-r)*(1-r));
		k -= (a+(n-1) *d)*pow(r,n)/(1-r);
		k +=n+pow(2,m);
		printf("%.2f\n",k);
	}
	return 0;
}
