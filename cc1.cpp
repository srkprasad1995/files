#include<iostream>
#include<vector>
#include<map>
#include<cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--)
	{
		long long n;
		scanf("%lld" , &n);
		long long res = n + (n * (n+1) /2);
		printf("%lld\n", res);
	}
	return 0;
}
