#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>

using namespace std;

long long tree[400009],flag[400009];

long long query(int node,int start,int end,int from,int to)
{
	if(to < start || from > end)
		return 0;
	if( from <= start && to >=end)
		return tree[node];
	else
	{
		int mid = (start+end)>>1;
		tree[(node<<1)+1] += ((long long)(mid - start+1))*flag[node];
		tree[(node<<1) + 2] += ((long long)(end - mid))*flag[node];
		flag[(node<<1)+1] += flag[node];
		flag[(node<<1) + 2] +=flag[node];
		flag[node] = 0;
		return query((node<<1)+1,start,mid,from,to) + query((node<<1)+2,mid+1,end,from,to);
	}
	return 0;
}

void update(int node,int start,int end,int from,int to,int val)
{
	if(to < start || from > end)
		return;
	if( from <=start && to >=end)
	{
		tree[node] += ((long long)(end -start+1)) * val;
		flag[node] += val;
	}
	else 
	{
		int mid = (start+end)>>1;
		tree[(node<<1)+1] += ((long long)(mid - start + 1))*flag[node];
		tree[(node<<1) + 2] += ((long long)(end - mid))*flag[node];
		flag[(node<<1)+1] += flag[node];
		flag[(node<<1) + 2] +=flag[node];
		flag[node] = 0;
		update((node<<1)+1,start,mid,from,to,val);
		update((node<<1 )+2,mid+1,end,from,to,val);
		tree[node] = tree[(node<<1)+1]+tree[(node<<1)+2];
	}
	return ;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c;
		scanf("%d %d",&n,&c);
		memset(tree,0,sizeof(tree));
		memset(flag,0,sizeof(flag));
		while(c--)
		{
			int op,i,j;
			scanf("%d",&op);
			if(op == 0)
			{
				int val;
				scanf("%d %d %d",&i,&j,&val);
				update(0,0,n-1,i-1,j-1,val);
			}
			else
			{
				scanf("%d %d",&i,&j);
				printf("%lld\n",query(0,0,n-1,i-1,j-1));
			}
		}
	}
	return 0;
}
