#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>

using namespace std;

bool b[1000001];

int main()
{
	int k,l,m,a[51];
	scanf("%d %d %d",&k,&l,&m);
	int max=INT_MIN;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		if(max < a[i])
			max = a[i];
	}
	b[0] = false;
	for(int i=1;i<=max;i++)
	{
		b[i] = !b[i-1];
		if(i>=k && !b[i-k]) b[i] = true;
		if(i>=l && !b[i-l]) b[i] = true;
	}
	for(int i=0;i<m;i++)
	{
		if(b[a[i]]) printf("A");
		else printf("B");
	}
	return 0;
}
