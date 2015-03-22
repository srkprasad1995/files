#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,q;
		scanf("%d %d %d",&n,&k,&q);
		char str[100001];int a[100001];
		scanf("%s",str);
		int l=0,r=n-1;
		int j=l;
		int cnt_0=0,cnt_1=0;		
		if(str[l]=='0') cnt_0++;else cnt_1++;
		for(int i=l;i<=r;i++)
		{
			if(i>l) if(str[i-1] =='0') cnt_0--;
					else cnt_1--;
			while(cnt_0 <=k && cnt_1<=k)
			{
				if(j>r){ break;}j++;
				if(str[j] =='0') cnt_0++;
				else cnt_1++;
			}
			a[i] = j;
		}
		while(q--)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			l--;r--;
			long long res = 0;
			for(int i=l;i<=r;i++)
			{
				if(a[i]<=r) res += a[i]-i;
				else res+=r-i+1;
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}
