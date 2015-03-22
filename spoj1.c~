#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long i,j,k=0,a[32100]={0};
	for(i=2;i<=32100;i++)
	{
		int f=0;
		for(j=2;j*j<i;j++)
		{
			if(j%i==0)
			{
				f=1;
				break;
			}
		}
		if(f==0)
			a[k++]=i;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,m;
		scanf("%lld %lld",&n,&m);
		if(n==1)
			n++;
		for(i=n;i<=m;i++)
		{	
			int f=0,k=0;
			for(j=a[k];j*j<=i;j=a[k++])
			{
				if(i%j==0)
				{
					f=1;
					break;
				}
			}
			if(f==0)
				printf("%lld\n",i);
		}
	}
	return 0;
}
