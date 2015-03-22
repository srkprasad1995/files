#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<climits>

using namespace std;


int knap(int o[],int nt[],int w[],int N,int O,int n)
{
	int dp[n+1][O+1][N+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=O;j++)
		{
			for(int k=0;k<=N;k++)
			{	
				if(j==0&&k==0)
					dp[i][j][k] = 0;
				else if(i==0) dp[i][j][k] = 999999999;
				else
					dp[i][j][k] = min(w[i-1]+dp[i-1][(j-o[i-1]<0)?0:j-o[i-1]][(k-nt[i-1])<0?0:k-nt[i-1]],dp[i-1][j][k]);
				//printf("%d  ",dp[i][j][k]);
			}
			//printf("\n");
		}//printf("\n");
	}
	return dp[n][O][N];
}
/*


	if(N<=0&&O<=0){
		return 0;}
	if(n==0 )
		return 676767676;
	int temp = min(w[n-1]+knap(o,nt,w,N-nt[n-1],O-o[n-1],n-1),knap(o,nt,w,N,O,n-1));
		return temp;
}
*/
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int O,N;
		scanf("%d %d",&O,&N);
		scanf("%d",&n);
		int o[1001];
		int nt[1001];
		int w[1001];
		for(int i=0;i<n;i++)
			scanf("%d %d %d",&o[i],&nt[i],&w[i]);
		int temp=knap(o,nt,w,N,O,n);
		printf("%d\n",temp);
	}
	return 0;
}
