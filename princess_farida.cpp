#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int t;
	scanf("%d",&t);
	int cnt=1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			printf("Case %d: %d\n",cnt++,0);
		else if(n==1)
		{
			int k;
			scanf("%d",&k);
			printf("Case %d: %d\n",cnt++,k);
		}
		else
		{
			long long a[100001];
			for(int i=0;i<n;i++)
				scanf("%lld",&a[i]);
			a[1] = max(a[0],a[1]);
			for(int i=2;i<n;i++)
			{
				a[i] = max(a[i]+a[i-2],a[i-1]);
			}
			printf("Case %d: %lld\n",cnt++,a[n-1]);
		}
	}	
	return 0;
}
