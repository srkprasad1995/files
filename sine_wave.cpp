#include<iostream>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

#define pdi pair<long double,int>

// Returns set bits in binary representation of x
void ass_hole(double low,double high,int t)
{
	if(t==0) return ;
	double mid  = (high+low)/2.0;
	ass_hole(low,mid,t-1);
	printf("%f %d-> ",mid,t);
	ass_hole(mid,high,t-1);
}
	

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,c,k;
		ass_hole(0.0,2.0,4);
		scanf("%d %d %d",&s,&c,&k);
		map<long double,int> M;
		map<long double,int> :: iterator it;
		for(int i=s-1;i<s;i++)
		{
			long long k = 1LL<<i;
			long double temp=0;
			while(temp <= 2)
			{
				if(M.find(temp) == M.end())
					M.insert(pdi(temp,2));
				else M[temp]++;
				printf("%Lf\n",temp);
				temp += 1.0/(long double)k;
			}
		}
		for(int i=0;i<c;i++)
		{
			long long k = 1LL<<i;
			long double temp=1.0/(long double)(2*k);
			while(temp <= 2)
			{
				if(M.find(temp) == M.end())
					M.insert(pdi(temp,1));
				else M[temp]++;
				temp += 1.0/(long double)k;
			}
		}
		int count=0;
		for(it = M.begin();it!= M.end();it++)
		{
			if(it ->second >=k)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
