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
		int n,m;
		scanf("%d %d",&n,&m);
		int temp=min(n,m);
		temp /= 2;
		temp = 2*temp;
		int n1 = n-temp;int m1 =m-temp;
		if(n1==1 && m>=n)
			printf("R\n");
		else if(m1==1 && n>=m)
			printf("D\n");
		else if(n1==0)
			printf("L\n");
		else printf("U\n");
	}
	return 0;
}
