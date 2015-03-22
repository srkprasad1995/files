#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

int sum[1000001];
int left_sum[1000001];
char str[100001];

void build_tree(int node,int low,int high)
{
	if(low == high)
		sum[node]=left_sum[node]= (str[low]=='('?1:-1);
	else
	{
		build_tree(node<<1,low,(low+high)/2);
		build_tree((node<<1)+1,((low+high)>>1)+1,high);
		sum[node] = sum[node<<1] + sum[(node<<1) +1];
		left_sum[node] = min(left_sum[node<<1],sum[node<<1]+left_sum[(node<<1)+1]);
	}
	return ;
}

void update(int node,int low,int high,int ind)
{
	if(ind>high || ind<low)
		return;
	if(low == high)
	{
		sum[node]=left_sum[node] = -sum[node];
		return ;
	}
	else
	{
		int m=(low+high)/2;
		update(node<<1,low,m,ind);
		update((node<<1)+1,m+1,high,ind);
		sum[node] = sum[node<<1] + sum[(node<<1) +1];
		left_sum[node] = min(left_sum[node<<1],sum[node<<1]+left_sum[(node<<1)+1]);
	}
	return ;
}

int main()
{
	int t=10;int cnt=1;
	while(t--)
	{
		int n;
		printf("Test %d:\n", cnt++);
		scanf("%d",&n);
		scanf("%s",str);
		build_tree(1,0,n-1);
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int k;
			scanf("%d",&k);
			if(!k)
				if(!sum[1] && !left_sum[1])
					printf("YES\n");
				else printf("NO\n");
			else 
				update(1,0,n-1,k-1);
		}
	}
	return 0;
}
