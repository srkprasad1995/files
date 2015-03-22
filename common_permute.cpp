#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int mini(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	char X[1000],Y[1000];
	while(scanf("%s %s",X,Y) != EOF)
	{
		int x[256] = {0},y[256] = {0};
		int lx = strlen(X);
		int ly = strlen(Y);
		for(int i = 0;i<lx;i++)
			x[X[i]]++;
		for(int i=0;i<ly;i++)
			y[Y[i]]++;
		for(int i='a';i<='z' ;i++)
		{
			int min=mini(x[i],y[i]);
			while(min -- )
				printf("%c",i);
		}
		printf("\n");
	}
	return 0;
}
