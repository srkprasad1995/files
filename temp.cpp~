#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

#define pdi pair<long double,int>

map<long double,int> M;
map<long double,int> :: iterator it;
int k;
int count ;
long long a[51];

int fun1(int s,int c,int k)
{
	memset(a,0,sizeof(a));
	a[s] = 1;
		for(int i=s-1;i>=1;i--)
			a[i] = 2*a[i+1];
		a[s]  = 3;
		if(c==0)
		{
			if(k>(s)) { return 0;}
			for(int i=s-1;i>=1;i--)
				a[i] += a[i+1];
	//		printf("%lld\n",a[k]);
		}
		else if(c<s)
		{
			if(k>(s)) {return 0;}
			int j=s-c;
			a[s] += a[s-1];
			for(int i=s-1;i>j;i--)
			{
				a[i] = a[i-1];
			}
			a[j] = 0;
			for(int i=s-1;i>=1;i--)
				a[i] += a[i+1];	
//			printf("%lld\n",a[k]);
		}
		else
		{
			if(s==0 && k==1 && c!=0) return (2*(pow(2,c)-1));
			if(k>s) {return 0;}
			a[s] += a[s-1];
			for(int i=s-1;i>1;i--)
				a[i] = a[i-1];
			a[1] = 0;
			for(int i=s-1;i>=1;i--)
				a[i] += a[i+1];
			a[1] = 2*pow(2,c)+1;
//			printf("%lld\n",a[k]);
		}	
		return a[k];
}

int fun2(int s,int c,int k)
{
	map<double,int> M;
		map<double,int> :: iterator it;
		for(int i=0;i<s;i++)
		{
			long long k = 1LL<<i;
			double temp=0;
			while(temp <= 2)
			{
				if(M.find(temp) == M.end())
					M.insert(pdi(temp,1));
				else M[temp]++;
				temp += 1.0/(double)k;
			}
		}
		for(int i=0;i<c;i++)
		{
			long long k = 1LL<<i;
			double temp=1.0/(double)(2*k);
			while(temp <= 2)
			{
				if(M.find(temp) == M.end())
					M.insert(pdi(temp,1));
				else M[temp]++;
				temp += 1.0/(double)k;
			}
		}
		int count=0;
		for(it = M.begin();it!= M.end();it++)
		{
			if(it ->second >=k)
				count++;
		}
		return count;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,c;
		for(int k=1;k<=25;k++)
		for(int s=0;s<=12;s++)
		for(int c=0;c<=12;c++)
		if(fun1(s,c,k)!=fun2(s,c,k))
		printf("%d %d %d\n",s,c,k);
	}
	return 0;
}
