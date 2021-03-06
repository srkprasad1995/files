#include<cstdio>
#include<iostream>
#include<cmath>
#include<stack>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;long long n;
		scanf("%lld %d",&n,&k);
		long long a[52],b[52];
		a[0] = 0;b[0] = 0;
		stack <int > s;
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&a[i]);
			b[i] = a[i] + 2*b[i-1];
		}
		bool f=0;
		for(int i=k;i>=1;i--)
		{
			if(b[i]<=n) 
			{
				s.push(i);
				n -= b[i];
			}
			if(!n)
			{
				f=1; break;
			}
		}
		if(!f) printf("-1");
		else while(!s.empty())
		{
			printf("%d ",s.top());
			s.pop();
		}
		printf("\n");
	}
	return 0;
}
