#include<iostream>
#include<cstdio>
using namespace std;
long long int a[500005];
int isp[10000000]={0};
int main()
{
	long long int temp;
	a[0] = 0;
	isp[0] = 1;
	int i;
	for(i=1;i<500005;i++)
	{
		temp = a[i-1] - i;
		if(isp[temp]==0 && temp>0)
		{
			a[i] = temp;
			isp[temp] = 1;
		}
		else
		{
			a[i] = a[i-1]+i;
			isp[a[i]] = 1;
		}
	}
	while(true)
	{
		int k;
		scanf("%d",&k);
		if(k==-1)
			break;
		printf("%lld\n",a[k]);
	}
	return 0;
}
