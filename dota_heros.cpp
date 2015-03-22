#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t -- )
	{
		int n,m,d,h,cnt = 0;
		scanf("%d %d %d",&n,&m,&d);
		int f = 0;
		while(n--)
		{
			scanf("%d",&h);
			if(h>d)
			{
				int k = h/d;
				if(h%d == 0)
					k--;
				cnt += k;
				if(cnt >=m)
				{
					f = 1;
				}
			}
		}
		if( f==1)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
