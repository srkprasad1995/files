#include<stdio.h>
#include<stdlib.h>

long long a[30][20];

long long rec(int n, int i, int j)
{
	if(n<12)
		return n;
	if(a[i][j]==0)
		a[i][j]=rec(n/2,i+1,j)+rec(n/3,i,j+1)+rec(n/4,i+2,j);
	return a[i][j];
}
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<30;i++)
		for(j=0;j<20;j++)
		a[i][j]=0;
		long long res=rec(n,0,0);
		printf("%lld\n",res);
	}
	return 0;
}
