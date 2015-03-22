#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,m,a[1000001];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int sum=a[0],res = -1;int j=1,k=0;
	while(j<n&&k<=j)
	{
		if(sum+a[j]<=m)
			sum += a[j++];
		else 
			sum -= a[k++];
		if(res < sum)
			res = sum;
	}
	printf("%d\n",res);
	return 0;
}
