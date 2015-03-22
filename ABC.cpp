#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;

char str[1000001];
pair<int , int > p[1000001];

int main()
{
	long long k,cnt;
	scanf("%s" , str);
	int l = strlen(str);
	long long i;
	int a=0 , b=0 ,c=0;
	p[0] = make_pair(0,0); 
	for( i = 1 ; i <= l ; i++)
	{
		if(str[i-1] == 'A')
			a ++;
		else if( str[i-1] == 'B')
			b ++;
		else c ++;
		p[i] = make_pair( a-b ,a -c);
	}
	pair< int , int > last( -1000000004 , -1000000004);
	sort( p , p+l+1);
	long long ans = 0 , plus = 0;
	for(i=0 ;i <= l ;i ++)
	{
		if(p[i] != last)
		{
			last = p[i];
			plus = 0;
		}
		ans += plus;
		plus += 1;
	}
	printf("%lld\n" , ans);
	return 0;
}
