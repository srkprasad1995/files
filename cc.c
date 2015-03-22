#include<stdio.h>
 
int count( int s[], int m, int n )
{
	int i,j,k,table[n+1][m+1];
	for(i=0;i<m;i++)
		table[0][i]=1;
	for(i=1;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			int x= (i>=s[j]) ? table[i-s[j]][j] : 0;
			int y= (j>=1)? table[i][j-1] :0;
			table[i][j]=x+y;
		}
	return table[n][m-1];
}
 
// Driver program to test above function
int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf(" %d ", count(arr, m, n));
    return 0;
}

