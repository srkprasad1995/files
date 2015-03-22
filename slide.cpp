#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int a[1000001];
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	int max = a[0];
	for(int i=1;i<k;i++)
		if(a[i]>max)
			max=a[i];
	printf("%d ",max);
	for(int i=k;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
		else if(max == a[i-k])
		{
			int r=a[i-k+1];
			for(int j=i-k+2;j<i;j++)
				if(a[j]>r)
					r=a[j];
			max = r;
		}
		printf("%d ",max);
	}
	return 0;
}
