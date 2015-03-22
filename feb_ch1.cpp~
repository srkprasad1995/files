#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[100002];
		scanf("%s",str);
		int l=strlen(str);
		int cnt1=0,cnt2 = 0;
		bool f=0;
		for(int i=0;i<l;i++)
		{
			if((f && str[i] == '+') || (!f && str[i] =='-'))
				cnt1++;
			if((f && str[i] =='-')||(!f && str[i] =='+'))
				cnt2++;
			f= !f;
		}
		printf("%d\n",(cnt1<cnt2 ? cnt1:cnt2));
	}
	return 0;
}
