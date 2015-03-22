#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int army[1002];
	for(int i=0;i<=m;i++)
		scanf("%d",&army[i]);
	int cnt_f=0;
	for(int i=0;i<m;i++)
	{
		int d = army[i] ^ army[m];
		int cnt = __builtin_popcount(d);
		if(cnt<=k) cnt_f++;
	}
	printf("%d",cnt_f);
	return 0;
}
