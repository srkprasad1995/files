#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

short a[6102][6102] = {{0}};
char str1[6101];
int lca(int l)
{	
	memset(a,0,sizeof(a));
	for( int i = 1; i <= l ; i++)
	{
		for( int j = 1 ; j <= l ; j++)
		{
			if(str1[i-1] == str1[l-j])
				a[i][j] = a[i-1][j-1] + 1;
			else
				a[i][j] = a[i-1][j] > a[i][j-1] ? a[i-1][j] : a[i][j-1];
		}
	}
	return l - a[l][l];
}

int main()
{
	int t;
	scanf("%d",&t);	
	while(t--)
	{
		scanf("%s",str1);
		int l=strlen(str1);
		printf("%d\n",lca(l));
	}
	return 0;
}
