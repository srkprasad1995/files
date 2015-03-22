#include<iostream>
#include<cstdio>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	while(true)
	{
		int n,W,i,w;
		scanf("%d %d",&W,&n);
		if(W==0 && n==0)
			break;
		int val[101],wt[101];
		for(i=0;i<n;i++)
			scanf("%d %d",&wt[i],&val[i]);
		int K[102][501],m[102][501];
		for(i = 0; i <= n; i++)
   		{
       			for(w=0; w<=W; w++)
       			{
			           if (i==0 || w==0)
               				K[i][w] = 0,m[i][w] = 0;
           			   else if (wt[i-1] <= w){
			                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
					if(K[i][w] == K[i-1][w])
						m[i][w] = m[i-1][w];
					else m[i][w] = m[i-1][w-wt[i-1]]+wt[i-1];
				}
           			    else{
                 			  K[i][w] = K[i-1][w];
						m[i][w] = m[i-1][w];}
       			}
   		}
	i=W;
             while(i){
                        if(K[n][i]==K[n][W])
                                i--;
                        else
                                break;
                }
  		 printf("%d %d\n",i+1,K[n][W]);
	}
	return 0;
}
