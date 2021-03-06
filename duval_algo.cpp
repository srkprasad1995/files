#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}

int duval(char str[])
{
	int i=0,j=1,k=0;
	int n=strlen(str);
	while(i+k < 2*n && j+k<2*n)
	{
		char a= i+k<n?str[i+k]:str[i+k-n];
		char b=j+k<n?str[j+k]:str[j+k-n];
		if(a>b)
		{
			i += k+1;
			k=0;
			if(i<=j) i=j+1;
		}
		else if(b>a)
		{
			j += k+1;
			k=0;
			if(j<=i) j=i+1;
		}
		else k++;
	}
	return min(i,j);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[10001];
		scanf("%s",str);
		printf("%d\n",duval(str)+1);
	}
	return 0;
}
