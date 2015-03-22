#include<cstdio>
#include<iostream>

using namespace std;
#define pii pair<int ,int>

int main()
{
	int n,c;
	scanf("%d %d",&n,&c);
	map < pii ,int> M;
	for(int i=0;i<n;i++)
	{
		int p,q;
		scanf("%d %d",p,q);
		M.insert(pii(p,q),0);
	}
	for(int i=1;i<n;i++)
	{
		
