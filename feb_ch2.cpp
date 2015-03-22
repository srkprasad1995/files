#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int a[100002]={0};
		scanf("%d",&n);
		int max = 0,k;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			if((++a[k]) > max)
				max = a[k];
		}
		printf("%d\n",(n-max));
	}
	return 0;
}
