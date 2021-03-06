#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,a[1001],b[1001];
		scanf("%d %d",&n,&m);n--;m--;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<m;i++) scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		reverse(b,b+m);
		reverse(a,a+n);
		int i=0,j=0,i_in=1,j_in=1;
		int sum =0 ;
		while(i<n && j<m)
		{
			if(a[i] > b[j])
			{
				sum += a[i]*i_in;
				i++;
				j_in++;
			}
			else
			{
				sum += b[j]*j_in;
				j++;
				i_in ++;
			}
		}
		while(i<n)
		{
			sum += a[i]*i_in;
			i++;
		}
		while(j<m)
		{
			sum += b[j]*j_in;
			j++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
