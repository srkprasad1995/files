#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	map <string , int > myMap;
	myMap["prasad"] = 234;
	myMap[ "pasupuleti"] = 347;
	myMap["sree"] = 453;
	
	myMap.insert( pair <string , int> ("nulu" , 9898));
	map<string ,int > :: iterator ii;
	for(ii = myMap.begin() ; ii !=myMap.end() ;ii++)
		cout << ii->first << "->" << ii->second <<endl;
	return 0;
}
