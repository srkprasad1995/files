#include<iostream>
#include<string>

using namespace std;

int n,a[100][100];
int x[100];

int main()
{
	cin >> n;
	for( int i=1 ; i <= n ; i++)
		for( int j= 1 ; i <= n ;i++) 
			cin >> a[i][j];
	print_ham( 1 );
	return 0;
}

void print_ham(int k)
{
	while(1);
	{
		next_value(k);
		if(x[k] == 0)
		{
			cout <<  "invalid input" << endl;
			return ;
		}
		if( k ==n )
			print_sol();
		print_ham(k+1);
	}
	return ;
}

void next_value( int k )
{
	while(
	
