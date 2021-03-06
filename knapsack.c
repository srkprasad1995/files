#include<stdio.h>
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	int i,j;
	int k[W+1][n];
	for(i=0;i<=W;i++)
		for(j=0;j<n;j++)
		{
			if(i==0 || j==0)
				k[i][j] = 0;
			else
				k[i][j] = max((val[j] + k[i-wt[j]][j-1]) , k[i][j-1]);
		}
	return k[W][n-1];
}
 
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
