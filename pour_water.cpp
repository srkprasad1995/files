#include<iostream>
#include<cstdio>
#include<climits>
#include<math.h>

using namespace std;

int gcd( int a , int b )
{
	if(b==0)
		return a;
	return gcd( b , a%b);
}

int find_step(int a , int b , int c)
{
	int a1=0,b1=0,step=0;
	while(a1 != c  &&  b1 != c)
	{
		if(a1 == 0)
		{
			a1 = a;
			step++;
		}
		else if(b1 == b)
		{
			b1=0;
			step ++;
		}
		else
		{
			int sum=a1 + b1;
			b1 = sum > b ? b : sum;
			a1 = sum - b1;
			step ++;
		}
	}
	return step;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a , b , c;
		scanf("%d %d %d" , &a , &b ,&c);
		if( c>max(a,b) || (c%gcd(a,b)))
			printf("-1\n");
		else 
		{
			int temp = min ( find_step (a ,b,c) , find_step (b ,a ,c));
			printf("%d\n",temp);
		}
	}
	return 0;
}
