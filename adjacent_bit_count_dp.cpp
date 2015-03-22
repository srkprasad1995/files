#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int ways(int n,int k

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		printf("%d\n",ways(n,k));
	}
	return 0;
}
