#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;
int digit[3000]={0};

int count(int n)
{
	if(n==2) return 3;
	if(n==1) return 2;
	return count(n-1) + count(n-2);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",count(n));
	return 0;
}
