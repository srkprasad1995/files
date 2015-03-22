#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,n,m,a[1001],b[1001];
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		int min=abs(a[0]-b[0]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(min>abs(a[i] - b[j]))
					min = abs(a[i] - b[j]);
		printf("%d\n",min);
	}
	return 0;
}
