#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,n,k,p,c;
		scanint(x);
		scanint(y);
		scanint(k);
		scanint(n);		
		bool f=0;
		while(n--)
		{
			scanint(p);
			scanint(c);
			if(p>=(x-y) && c<=k)
				f=1;
		}
		if(f)
			printf("LuckyChef\n");
		else 
			printf("UnluckyChef\n");
	}
	return 0;
}
