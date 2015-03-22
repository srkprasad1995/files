#include<iostream>
#include<cstdio>
#include<map>
#include<cstdlib>
#include<cstring>

using namespace std;

#define pii pair<int ,int>

int main()
{
	map<long long ,pii> M;
	map<long long ,pii> :: iterator it;
	int q;
	scanf("%d",&q);
	for(int c=0;c<q;c++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			long long n;int  p;
			scanf("%lld %d",&n,&p);
			M[n] = pii(p,c);
		}
		else 
		{
			long long n;int color=0;
			scanf("%lld",&n);
			int max = -1;
			while(n>0)
			{
				if((it = M.find(n)) != M.end() && (*it).second.second>max)
				{
					color = (*it).second.first;
					max = (*it).second.second;
				}
				n=n>>1;
			}
			printf("%d\n",color);
		}
	}
	return 0;
}
