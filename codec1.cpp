#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long k,a[100001],b[100001],max = 0;
		scanf("%d %lld",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%lld",&b[i]);
		for(int i=0;i<n;i++)
		{
			long long temp = (k/a[i]);
			temp *= b[i];
			if(temp > max)
				max = temp;
		}
		printf("%lld\n",max);
	}
	return 0;
}
