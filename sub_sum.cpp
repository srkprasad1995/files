#include<iostream>
#include<stdlib.h>

using namespace std;

int n;
int a[100],x[100];
int m;

void sub_sum(int , int ,int );
void print_sol();

int main()
{
	int sumf = 0;
	cin >> n;
	for ( int i =0 ;i < n ;i ++)
	{
		cin >> a[i];
		sumf += a[i];
	}
	cin >> m;
	sub_sum( 0,  0 , sumf );
	return 0;
}

void sub_sum( int sum , int k , int sumf)
{
	x[k] = 1;
	if( sum + a[k] == m)
		print_sol();
	else if (sum + a[k] + a[k+1] <= m)
		sub_sum(sum + a[k] , k+1 , sumf -a[k]);
	if(sum + sumf - a[k] >=m && sum+a[k+1] <=m)
	{
		x[k] = 0;
		sub_sum( sum , k+1 , sumf-a[k]);
	}
	x[k] = 0;
	return ;
}

void print_sol()
{
	for(int i=0 ;i < n ; i++)
		cout << x[i] << " " ;
	cout << endl;
	return ;
}
	

