#include<stdio.h>
 
// Prototype of a utility function that returns minimum of two integers
int min(int a, int b);
 
// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
	int c[n+1][k+1];
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=min(i,k);j++)
		{
			if(j==0 || i==j)
				c[i][j] = 1;
			else
				c[i][j]=c[i-1][j-1] + c[i-1][j];
		}
	return c[n][k];
}
 
// A utility function to return minimum of two integers
int min(int a, int b)
{
    return (a<b)? a: b;
}
 
/* Drier program to test above function*/
int main()
{
    int n = 5, k = 2;
    printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) );
    return 0;
}
