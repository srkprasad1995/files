#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double a,d,c; int n,p;
		cin >> a >> d >> c >> p >>n;
		if(n<=(int)a) printf("0\n");
		else
		{
			double a1 = c,b1=2*d + c,c1 = 2*(a-(double)n);
			double temp = sqrt((b1*b1)-(4*a1*c1));
			temp -= b1;
			temp /= 2*a1;
			int k = (int)temp;
			if(k<temp) k++;
			printf("%d\n",p*k);
		}
	}
	return 0;
}
