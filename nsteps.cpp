#include<iostream>
#include<cstdio>
#include<algorithm>

int main()
{
	int t;
	scanf( "%d" , &t);
	while( t--)
	{
		int x,y;
		scanf("%d %d",&x, &y);
		if( x == y)
		{
			if ( x % 2)
				printf("%d\n" , (2*x - 1) );
			else printf( "%d\n" , 2*x);
		}
		else if( x == (y+2))
		{
			if( x%2)
				printf("%d\n" , (2*y + 1));
			else printf("%d\n" ,  (2*y + 2));
		}
		else printf("No Number\n");
	}
	return 0;
}
