#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,root=0;
		cin >> n;
		while(n--)
		{
			int id , sum_id;
			cin >> id >> sum_id;
			root += id - sum_id;
		}
		cout << root << endl;
	}
	return 0;
}
