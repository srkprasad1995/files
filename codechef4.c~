#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a[1000001]={0};
		scanf("%d",&n);
		int i=1,k=0;
		while(i<n)
		{
			a[k++]=i;
			int temp=n/i;
			i=n/temp + 1;
		}
		for(i=0;i<k;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
