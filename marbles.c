#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,k,j,res=1;
		scanf("%lld %lld",&n,&k);
		n=n-1;k=k-1;
		k=k>n-k ? n-k : k;
		for( j=1; j<=k;j++,n--)
		{
			if(n%j==0)
				res *= n/j;
			else if(res % j==0)
				res = res/j * n;
			else
				res=(res*n)/j;
		}
		printf("%lld\n",res);
	}
	return 0;
}
