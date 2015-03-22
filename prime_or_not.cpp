#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

long long modulo(long long a,long long b,long long c)
{
	long long x=1,y=a;
	while(b>0)
	{
		if(b&1)
		{
			x = (x*y)%c;
		}
		y=(y*y)%c;
		b/=2;
	}
	return x%c;
}

bool fermat(long long p)
{
	long long x;
	if(p==2)
		return 1;
	for(long long i=0;i<10;i++)
	{
		x=rand()%p;
		if(x==0||x==1)
			x++;
		if(modulo(x,p-1,p) !=1)
			return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long p;
		scanf("%lld",&p);
		if(fermat(p))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
