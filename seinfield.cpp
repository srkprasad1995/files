#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;

int main()
{
	char str[2001];
	int t=1;
	while(scanf("%s",str) && str[0] != '-' )
	{
		int cnt =0 ;
		int l=strlen(str);
		stack<char> s;
		for(int i=0 ; i<l ; i++)
		{
			if(str[i] == '{')
				s.push('{');
			else 
			{
				if(s.empty())
				{
					cnt ++;
					s.push('{');
				}
				else s.pop();
			}
		}
		int k = s.size();
		cnt += k/2;
		printf("%d. %d\n",t++,cnt);
	}
	return 0;
}
		
