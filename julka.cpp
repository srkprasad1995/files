#include<iostream>
#include<cstdio>

using namespace std;

char tot[111],diff[111],natu[111],ritu[111];

int main()
{
	int t=10;
	while(t--)
	{
		scanf("%s %s",tot,diff);
		calculate();
	}
	return 0;
}

void calculate()
{
	int i,j,k;
	int n=strlen(tot);
	int m= strlen(diff);
	
