#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstring>

using namespace std;
int a[1000001];

int find_len( int m , int low , int high )
{
	if(a[high - low])
		return a[high - low];
	if( (low+1) == high )
		return 0;
	int sum = (high - low);
	int max = INT_MIN;
	for( int i = low+1 ; i < high ; i++)
	{
		int left = find_len( m , low , i );
		int right = find_len( m , i , high);
		if( max < (sum + left + right)  && (left + right + sum) <=m && left>=0 && right >=0)
			max = left + right+sum;
	}
	a[high - low] = max;
	return  max;
}

int main()
{
	int t;
	scanf("%d " ,&t);
	while(t--)
	{
		memset( a , 0 , sizeof(a));
		int n,m;
		scanf("%d %d" , &n , &m);
		int k =  find_len( m , 0 , n+1 );
		if( k < 0)
			printf( "-1\n");
		else  printf("%d\n" ,m - k);
	}
	return 0;
}
