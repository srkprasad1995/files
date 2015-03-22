#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<stack>

using namespace std;

char str[100001];
int l,type;

long long solve(char ch1,char ch2)
{
	stack<int > s1;
	stack<int > s2;
	for(int i=0;i<l;i++)
	{
		if(str[i] == ch1 && (i&1)) s1.push(i);
		if(str[i] == ch2 && !(i&1))s2.push(i);
	}
	long long res = 0;
	while(!s1.empty() && !s2.empty())
	{
		int id1 = s1.top();s1.pop();
		int id2 = s2.top();s2.pop();
		res += pow(abs(id1-id2),type);
	}
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&type);
		if(type ==2) type--;
		scanf("%s",str);
		l=strlen(str);
		int c_B=0,c_G=0;
		for(int i=0;i<l;i++)
			if(str[i] == 'B') c_B++;
			else c_G++;
		if(abs(c_B-c_G)>1) {printf("-1\n");continue;}
		if(c_B>c_G) {printf("%lld\n",solve('B','G'));continue;}
		if(c_B<c_G) {printf("%lld\n",solve('G','B'));continue;}
		else printf("%lld\n",min(solve('G','B'),solve('B','G')));
	}
	return 0;
}
		
