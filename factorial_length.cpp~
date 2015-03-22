#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int a[1000001];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int m = 0;
		a[m++] = 1;
		for( int i = 1 ;i<=n;i++)
		{
			int prod,temp=0;
			for( int j = 0 ; j<m ; j++)
			{
				prod = a[j]*i + temp;
				a[j] = prod % 10;
				temp = prod /10;
			}
			while(temp)
			{
				a[m++] = temp%10;
				temp = temp/10;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}
