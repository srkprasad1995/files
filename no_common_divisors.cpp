#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int temp=n<m?gcd(m,n):gcd(n,m);
		int k=sqrt(temp),cnt=0;
		printf(" temp is here  %d\n",k);
		for(int i=1;i<=k;i++)
		{
			if(temp%i == 0)
				cnt +=2;
		}
		if(!(temp % k) && k*k == temp)
			cnt --;
		printf("%d\n",cnt);
	}
	return 0;
}
