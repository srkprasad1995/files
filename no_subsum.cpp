#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;


int sub_sum(int arr[],int n,int W)
{
	if(W==0)
		return 1;
	if( n ==0 )
		return 0;
	return (sub_sum(arr,n-1,W)+sub_sum(arr,n-1,W-arr[n-1]));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int arr[22];int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		if(sum%k)
			printf("no\n");
		else 
		{
			int W=sum/k;
			int temp=sub_sum(arr,n,W);
			if(temp > k)
				printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
