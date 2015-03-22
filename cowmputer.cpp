#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if(n==0)
		printf("0\n");
	else {
		int i=-2;
		string s="";
		while(n)
		{
			if((n%i)<0)
			{
				s=char ((n%2)+2 +'0')+s;
				n = n/i +1;
			}
			else {
				s=char ((n%i)+'0')+s;
				n=n/i;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
