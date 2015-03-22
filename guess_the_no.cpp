#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	while(true)
	{
		char str[21];
		scanf("%s",str);
		if(str[0] == '*')
			break;
		long long lcm = 1;
		int l=strlen(str);
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'Y')
			{
				long long g=lcm>(i+1) ? gcd(lcm,i+1) : gcd(i+1,lcm);
				lcm = lcm * (i+1) /g;
			}
		}
		long long s = sqrt(lcm);
		int f=0;
		for(int i=1;i<=s;i++)
		{
			int k = lcm/i;
			if(lcm%i ==0)
			{
				if((k<=l && str[k-1] =='N') || (i<=l &&str[i-1] =='N')){ f=1;break;}
			}
		}
		if(f)
			printf("-1\n");
		else printf("%lld\n",lcm);
	}
	return 0;
}
		
		
	
