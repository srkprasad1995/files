#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

#define pii pair<int ,int >

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[101],b[101],max =0;
		for(int i=0;i<n;i++)
			scanf("%d %d",&a[i],&b[i]);
		int current = 0;
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0,j=0;j<n,i<n; )
		{
			if(a[i] < b[j])
				current++,i++;
			else current--,j++;
			max = max>current ? max : current;
		}
		printf("%d\n",max);
	}
	return 0;
}
