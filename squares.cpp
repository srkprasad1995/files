#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(!n) break;
		printf("%d\n",(n*(n+1)*(2*n+1))/6);
	}
	return 0;
}
