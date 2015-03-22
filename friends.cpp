#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<bitset>
#include<cmath>

using namespace std;

int main()
{
	bitset <2003> friends[2003];
	int n;
	scanf("%d",&n);
	char s[n];
	for(int i = 0 ; i < n ;i++)
	{
		scanf("%s" , s);
		for(int j=0;j<n;++j)
		{
			if(s[j]=='1')
		        	friends[i][j]=1;
		      	else
		        	friends[i][j]=0;
      		}
    	}
	int cnt=0;
	for(int i = 0 ;i < n ;i ++)
		for(int j=i+1 ; j < n; j++)
			if( !friends[i][j]  && (friends[i] & friends[j]).any())
				cnt += 2;
	printf("%d\n" , cnt );
	return 0;
}
	
