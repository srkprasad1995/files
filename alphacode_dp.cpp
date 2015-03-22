#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
	while(true)
	{
		char str[5002];
		scanf("%s",str);
		if(!strcmp(str,"0"))
			break;
		int n=strlen(str);
		long long dp[5002];
		int f=0;
		dp[n]=1;
		dp[n-1]=(str[n-1]!='0'); 
		for(int i=n-2;i>=0;i--)
		{
			if(str[i] == '0'){
				dp[i] =0;continue;
			}
			dp[i] = dp[i+1];
			if(((str[i]-'0')*10+str[i+1]-'0')<27)
				dp[i] += dp[i+2];
		}
		if(f) printf("0\n");
		else printf("%lld\n",dp[0]);
	}
	return 0;
}
