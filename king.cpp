#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;

int main () {
  string line;
  ifstream myfile ("prasad.txt");
  if (myfile.is_open())
  {
    while ( getline(myfile,line) )
    {
      int l=line.size();
	int a = line[0] - '0';
	int b = line[1] -'0';
	int i = 2;
	while(i<l)
	{
		int c = line[i]-'0';
		int d = line[i+1]-'0';
		printf("%d %d\n",c,d);
		i += 2;
	}
	printf("\n\n\n");
     }
    }
    myfile.close();
  return 0;
}
