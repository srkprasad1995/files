#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int a[99000000];

int main()
{
	while(true)
	{
		char str[5];
		scanf("%s",str);
		if(!strcmp(str,"00e0")) break;
		int n = (str[0]-'0')*10+(str[1]-'0');
		n *= pow(10,str[3]-'0');
		int i;
		for(i=31;i>=0;i--)
			if((n>>i)) break;
		int p=pow(2,i);
		printf("%d\n",2*(n-p)+1);
	}
	return 0;
}
	
	
