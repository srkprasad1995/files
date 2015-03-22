#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>

using namespace std;

int a[100001][3];
long long int cost[100001][3]={{0}};

long long min(long long a,long long b)
{
	return a<b?a:b;
}
long long min(long long a,long long b,long long c,long long d)
{
	long long min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;
	if(d<min)
		min=d;
	return min;
}

long long min(long long a,long long b,long long c)
{
	long long min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;
	return min;
}

int main()
{
	int cnt=0;
	while(true)
	{
		cnt++;
		int n;
		scanf("%d",&n);
		if(n==0) break;
		for(int i=0;i<n;i++)
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		cost[n-1][1] = a[n-1][1];
		cost[n-1][0]=a[n-1][0] + cost[n-1][1];
		cost[n-1][2]=INT_MAX;
		for(int i=n-2;i>=0;i--)
		{
			cost[i][2]=a[i][2]+min(cost[i+1][1],cost[i+1][2]);
			cost[i][1]=a[i][1]+min(cost[i+1][0],cost[i][2],cost[i+1][1],cost[i+1][2]);
			cost[i][0]=a[i][2]+min(cost[i+1][0],cost[i][1],cost[i+1][1]);
		}
		printf("%d. %lld\n",cnt,cost[0][1]);
	}
	return 0;
}
