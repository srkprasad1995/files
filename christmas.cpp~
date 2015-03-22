#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int cmpr(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,a[20001] = {0};
		scanf("%d %d",&n,&k);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		qsort(a,n,sizeof(int ),cmpr);
		int min = a[k-1] - a[0];
		for(int i=k; i < n;i ++)
		{
			if( (a[i] - a[i-k+1]) < min)
				min = a[i] - a[i-k+1];
		}
		printf("%d\n",min);
	}
	return 0;
}
