#include<iostream>

using namespace std;

void print_sol( int [] , int );
bool place (int , int ,int []);
void print_nqueen( int , int , int []);
int abs(int x);

int main()
{
	int n;
	int x[20] = { 0 };
	cin >> n;
	print_nqueen( 1 , n , x );
	return 0;
}

void print_nqueen(int k , int n , int x[])
{
	for(int i=1; i <= n ;i ++)
	{
		if(place( k ,  i ,  x))
		{
			x[k] = i;
			if(k==n)
				print_sol( x , n);
			else print_nqueen( k+1 , n , x);
		}
	}
	return ;
}

bool place( int k , int i , int x[])
{
	for(int j = 1 ; j < k ; j++)
	{
		if((x[j] == i) || (abs(x[j] - i) == abs( j - k)))
			return false;
	}
	return true;
}

void print_sol( int x[] , int n)
{
	for(int i = 1; i <= n ;i ++)
		cout << x[i] << " ";
	cout << endl;
	return ;
}

int abs(int x)
{
	if(x < 0)
		x= -x;
	return x;
}
