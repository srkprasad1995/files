#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<string> ss;
	ss.push_back(" the number is 10");
	ss.push_back(" the number is 20");
	ss.push_back(" the number is 30");

	cout << "Loop by index:: " << endl;

	int i;
	for(i=0; i<ss.size();i++)
	{
		cout << ss[i] << endl;
	}
	cout << endl << "constraint iterator: " << endl;

	vector<string> :: iterator ii;
	for( ii = ss.begin() ; ii !=ss.end() ; ii++)
		cout << *ii << endl;
	
	cout << endl << "Reverse iterator : " << endl;
	
	vector <string> :: reverse_iterator rii;
	for(rii = ss.rbegin() ; rii != ss.rend() ; rii++)
		cout<<*rii << endl;
	cout << endl << "sample output " << endl;
	
	cout << ss.size() << endl;
	cout << "first print:" << ss[2] << endl;
	swap(ss[0] , ss[2]);
	cout << " second print:"<< ss[2] << endl;
}

