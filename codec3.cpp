#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		long long sum = 0,k;
		for(long long i=0;i<n;i++)
		{
			scanf("%lld",&k);
			sum += k;
		}
		if(sum < 100 || sum >= (100+n))
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
