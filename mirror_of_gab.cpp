#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[20];
		scanf("%s",str);
		int l=strlen(str);
		int i,k=l/2;
		for(i=0;i<k;i++)
		{
			if(str[i] != str[l-i-1])
				break;
		}
		if(i==k)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
