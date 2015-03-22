#include<iostream>
#include<cstdio>
#include<map>
#include<string>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int accnts;char str[33];		
		map<string,int> table;
		scanf("%d\n",&accnts);
		while(accnts --)
		{
			gets(str);
			table[str]++;
		}
		map<string , int > :: iterator i;
		for( i= table.begin() ; i!=table.end();i++)
		{
			printf("%s %d\n",i->first.c_str(),i->second);
		}
		puts(" ");
	}
	return 0;
}
