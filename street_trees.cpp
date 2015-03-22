#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int gcd_of(int a,int b)
{
	if(b==0)
		return a;
	return gcd_of(b,a%b);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[100001],gcd;
	long long sum=0;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
		a[i] = a[i+1] - a[i];
	gcd = a[0];
	for(int i=1;i<n-1;i++)
		gcd = gcd > a[i] ?gcd_of(gcd,a[i]):gcd_of(a[i],gcd);
	for(int i=0;i<n-1;i++)
		sum += a[i]/gcd -1;
	printf("%lld",sum);
	return 0;
}
