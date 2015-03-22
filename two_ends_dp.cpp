#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int d[1001][1001];

int dp( int a[],int low,int high)
{
	if(d[low][high] != -1) return d[low][high] ;
	if(low == high)
	{
		d[low][high] = a[low];
		return a[low];
	}
	int m;
	if(low+1 == high)
	{
		d[low][high] = max(a[low]-a[high],a[high]-a[low]);
		return max(a[low]-a[high],a[high]-a[low]);
	}
	if(a[low+1]>=a[high]) m = a[low] - a[low+1] +dp(a,low+2,high);
	else m = a[low] - a[high] + dp(a,low+1,high-1);
	if(a[low]>=a[high-1])m = max(m,a[high] - a[low] +dp(a,low+1,high-1));
	else m =max(m, a[high] - a[high-1] + dp(a,low,high-2));
	d[low][high] = m;
	return m;
}

int main()
{
	int cnt=0;
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(!n) break;
		int a[1001];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(d,-1,sizeof(d));
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++cnt,dp(a,0,n-1));
	}
	return 0;
}
