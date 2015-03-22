#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define pii pair<int ,int>

int main()
{
	int n;
	vector<string > vect;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		string str;
		cin >> str;
		vect.push_back(str);
	}
	sort(vect.begin(),vect.end());
	printf("--------------------\n");
	for(int i=0;i<n;i++)
		cout << vect[i]<<endl;
	return 0;
}
