#include<stdio.h>
#define M 1000000007

int main()
{
		int n;
		scanf("%d",&n);
		if(n<13)
		{
			printf("0\n");
		}
		else if(n==13|| n==14)
		{
			printf("1\n");
		}
		else 
		{
			unsigned long long int m = (n-13);m=m/2;
			unsigned long long int prod1=((m+6)*(m+5)*(m+4));prod1=prod1/6;
			unsigned long long int prod2=((m+3)*(m+2)*(m+1));prod2=prod2/6;
			if(prod1%5)
				prod2 = prod2/5;
			else prod1 =prod1/5;
			if(prod1%4==0)
				prod1=prod1/4;
			else if(prod2%4 == 0)
				prod2 = prod2/4;
			else 
			{
				prod1 = prod1/2;
				prod2 = prod2/2;
			}
			prod1=prod1%M;
			prod2=prod2%M;
			unsigned long long int prod =(prod1 * prod2)%M;
			printf("%lld\n",prod);
		}
	return 0;
}
