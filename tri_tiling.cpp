#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int f[31],g[31];
	f[0]=g[1]=1;
	g[0]=f[1]=0;
	for(int i=2;i<31;i++)
	{
		f[i]=f[i-2]+2*g[i-1];
		g[i]=f[i-1]+g[i-2];
	}
	int n;
	while(true)
	{
		scanf("%d",&n);
		if(n==-1) break;
		printf("%d\n",f[n]);
	}
	return 0;
}
