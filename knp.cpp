#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

void print_Mat( char [] , char [] );
void find_prefix( char [] , int [] );

int main()
{
	char txt[40];
	char pattern[10];
	cin >> txt;
	cin >> pattern;
	print_Mat (txt , pattern);
	return 0;
}

void print_Mat( char txt[] , char pattern[] )
{
	int n = strlen ( txt ) ;
	int m = strlen (pattern);
	int kmp[20];
	find_prefix( pattern , kmp );
	int k = -1;
	for( int i = 0 ; i < n ; i++)
	{
		while( k >= 0  && txt[i] != pattern[k+1])
			k = kmp[k];
		if(txt [i] == pattern[k+1])
			k++;
		if( k == m-1 )
		{
			cout << " index matched at: " << (i - m+1) << endl;
			k = kmp [k];
		}
	}
	return ;
}
void find_prefix( char pattern[] ,int kmp [])
{
	int m = strlen ( pattern );
	int k = -1;
	kmp [ 0 ] = -1;
	for( int i = 1 ; i < m ; i++)
	{
		while ( k >= 0 && pattern [ k+1] != pattern [i])
			k = kmp[k];
		if(pattern[k+1] == pattern[i])
			k++;
		kmp [i] = k;
	}
	
	for( int i = 0 ;i  < m ; i++ )
	{
		cout << kmp[i] << " " ;
	}
	cout << endl;
	return ;
}
