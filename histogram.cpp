#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stack>

using namespace std;

int main()
{
	while(true)
	{
		long long n;
		scanf("%lld",&n);
		if(n==0) break;
		long long a[100001];
		for(long long i=0;i<n;i++)
			scanf("%lld",&a[i]);
		stack<long long > s;
		long long max = 0;
		s.push(0);
		for(long long i=1;i<n;i++)
		{
			while(!s.empty() && a[i]<a[s.top()])
			{
				long long tp = s.top();
           			s.pop(); 
            			long long area_with_top = a[tp] * (s.empty() ? i : i - s.top() - 1);
				if(max < area_with_top)
					max = area_with_top;
			}
			s.push(i);
		}
		while(!s.empty())
		{
			long long tp = s.top();
           		s.pop(); 
            		long long area_with_top = a[tp] * (s.empty()?n : n - s.top() - 1);
				if(max < area_with_top)
					max = area_with_top;
		}
		printf("%lld\n",max);
	}
	return 0;
}
