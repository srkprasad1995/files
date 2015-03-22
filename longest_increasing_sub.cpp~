#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n,lis[13],a[13];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	lis[0] = 1;
	for(int i=1;i<n;i++)
	{
		int max = 1;
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]<a[i] && max<(lis[j]+1))
				max = lis[j]+1;
		}
		lis[i] = max;
	}
	int max = lis[0];
	for(int i=1;i<n;i++) max=lis[i]>max?lis[i]:max;
	printf("%d\n",max);
	return 0;
}
