#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p;
		scanf("%d %d",&n,&p);
		int a[1000001];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int rp=0,rsum=0;
		int fp=0,fsum=0,j=0;
		for(int i=0;i<n;i++)
		{
			if(rsum+a[i] <=p)
			{
				rsum += a[i];
				rp ++;
			}
			else
			{
				while(rsum+a[i] > p)
				{
					rsum -= a[j++];
					rp --;
				}
				rsum += a[i];
				rp ++;
			}
			if((fp < rp) || ( (fp == rp) && (rsum<fsum)))
			{
				fp = rp;
				fsum = rsum;
			}
		}
		printf("%d %d\n",fsum,fp);
	}
	return 0;
}
