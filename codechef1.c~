#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define M 1000000007

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[100001];
		scanf("%s",str);
		int i,l=strlen(str);
		long long ans=1;
		for(i=0;i<l;i++)
		{
			if(i%2==0)
			{
				if(str[i] == 'l')
					ans=(ans*2)%M;
				else ans=(ans*2 + 2)%M;
			}
			else
			{
				if(str[i] == 'l')
					ans = (ans*2 -1)%M;
				else ans = (ans*2 +1)%M;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
