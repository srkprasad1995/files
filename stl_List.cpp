#include<iostream>
#include<list>
#include<string>

using namespace std;

int main()
{
	list<int > temp;
	temp.push_back(0);
	temp.push_front(0);
	temp.insert( ++temp.begin() ,0 );

	temp.push_back(5);
	temp.push_back(6);
	
	list <int> :: iterator ii;
	for( ii = temp.begin() ; ii != temp.end() ; ii++)
		cout<< *ii << " " ;
	cout << endl ;
	return 0;
}
