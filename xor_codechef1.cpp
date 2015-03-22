#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int xoror(int set[],int n,int k)
{
	int i,a[1001];
	for(i=0;i<=n;i++)
	{
		if(i==0)
			a[i] = k;
		else 
		{
			a[i] = max(a[i-1]^set[i-1],a[i-1]);
		}
	}
	return a[n];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int set[1001],n,k;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&set[i]);
		printf("%d\n",xoror(set,n,k));
	}
	return 0;
}
