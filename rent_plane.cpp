#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>

using namespace std;

#define pii pair<int ,int>
#define pp pair<pii , int>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==0) {printf("0\n");continue;}
		vector<pp> a;
		for(int i=0;i<n;i++)
		{
			int s,d,p;
			scanf("%d %d %d",&s,&d,&p);
			a.push_back(pp(pii(s+d,s),p));
		}
		long long lcs[10001]={0};
		lcs[0] = a[0].second;
		for(int i=1;i<n;i++)
			for(int j=0;j<i;j++)
			{
				if(lcs[i] < lcs[j]+a[i].second && a[i].first.second>=a[j].first.first)
					lcs[i] = lcs[j]+a[i].second;
			}
		long long ma = 0;
		for(int i=0;i<n;i++)
			ma = max(ma,lcs[i]);
		printf("%lld\n",ma);
	}
	return 0;
}
