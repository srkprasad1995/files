#include<cstdio>
#include<iostream>
#include<map>
#include<cstdlib>

using namespace std;
#define pii pair<int ,int>

long long sum;
map<int ,pii> M;

int main()
{
	int n,k;
	scanf("%d",&n);
	map<int ,pii>:: iterator it;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&k);
			M[k]=pii(i,j);
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&k);
			it = M.find(k);
			sum += (i-(*it).second.first)*(i-(*it).second.first) + (j-(*it).second.second)*(j-(*it).second.second);
		}
	printf("%lld",sum);
	return 0;
}
