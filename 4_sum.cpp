#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>	 
#include<algorithm>

int sum1[10000001];
int sum2[10000001];
using namespace std;

int bin_search(int arr[],int key,int k)
{
	int iter=0;
	int low=0,high=k-1;
	while(low<=high)
	{
		int mid = (high + low)/2;
		if(key==arr[mid])
		{
			int temp =  mid-1;
			while(arr[mid] == key && mid<k)
			{
				mid++;
				iter++;
			}
			while(temp>=0&& arr[temp]==key)
			{
				temp--;
				iter++;
			}
			return iter;
		}
		else if(arr[mid]>key)
			high = mid-1;
		else low=mid+1;
	}
	return 0;
}

int main()
{
	int n;
	int a[4000],b[4000],c[4000],d[4000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	int k=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			sum1[k++]=a[i]+b[j];
	sort(sum1,sum1+k);
	k=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			sum2[k++] = -1*(c[i]+d[j]);
	sort(sum2,sum2+k);
	int ans=0;
	for(int i=0;i<k;)
	{
		int j=i;
		int p=0;
		while(sum1[j] == sum1[i] && j<k) p++,j++;
		ans += p*bin_search(sum2,sum1[i],k);
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}
