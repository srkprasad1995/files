#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n&1)
			printf("%d\n",n/2+1);
		else printf("%d\n",n/2);
	}
	return 0;
}
