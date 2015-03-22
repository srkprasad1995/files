#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;
int n,c,arr[100001];

int cmpr( const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int fun(int x)
{
	int lastPos=arr[0];
	int cowCnt = 1;
	for(int i = 1; i<n;i++)
	{
		if(arr[i]-lastPos >= x)
		{
			cowCnt ++;
			if(cowCnt == c)
				return 1;			
			lastPos = arr[i];
		}
	}
	return 0;
}

int binSer()
{
	int start = 0 , end = arr[n-1];
	while(start  < end )
	{
		int mid = (start + end)/2;
		if(fun(mid))
			start = mid+1;
		else end = mid;
	}
	return start-1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&c);
		for(int i=0 ; i<n ; i++)
			scanf("%d",&arr[i]);
		qsort(arr,n,sizeof(int),cmpr);
		printf("%d\n",binSer());
	}
	return 0;
}

