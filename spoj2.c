#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int t=24;
	while(t--)
	{
		char str1[1000],str2[1000];
		scanf("%s %s",str1,str2);
		if(strstr(str1,str2))
			printf("1\n");
		else printf("0\n");
	}
	return 0;
}
