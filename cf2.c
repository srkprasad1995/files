#include<stdio.h>

#include<stdlib.h>

int cmpr(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,a[400],visited[401]={0};
		scanf("%d %d ",&n,&m);
		int i,cnt=0,max;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			visited[a[i]]++;
		}
		max=a[1];
		for(i=1;i<=m;i++)
		{
			if(max<a[i])
				max=a[i];
		}
		for(i=0;i<=max;i++)
			printf("%d",visited[i]);
		qsort(visited,max+1,sizeof(int),cmpr);
		for(i=0;i<=max;i++)
			printf("%d",visited[i]);
		for(i=0;i<n-1;i++)
		{
			cnt++;
		}
		for(i=n-1;i<max;i++)
		{
			cnt+=visited[i];
		}	
		printf("%d\n",cnt);
	}
	return 0;
}
