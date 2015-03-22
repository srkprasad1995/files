#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>

using namespace std;

int main()
{
	int n,m,k,a[101][101],cost[101][101];
	scanf("%d %d",&n,&m);
	if(n==0 || m==0){
		printf("0");return 0;}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<m;i++)
		cost[n-1][i] = a[n-1][i];
	if(n>1)
	{
		for(int i=n-2;i>=0;i--)
			for(int j=0;j<m;j++)
			{
				int min =INT_MAX;
				if(min > cost[i+1][j])
					min = cost[i+1][j];
				if(j<m-1 && min>cost[i+1][j+1])
					min = cost[i+1][j+1];
				if(j>0 && min > cost[i+1][j-1])
					min = cost[i+1][j-1];
				cost[i][j] = min+a[i][j];
			}
	}
	int mini = INT_MAX;
	for(int i=0;i<m;i++)
		if(mini>cost[0][i])
			mini = cost[0][i];
	printf("%d",mini);
	return 0;
}
