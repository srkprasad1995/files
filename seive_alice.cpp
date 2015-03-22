#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	bool isPrime[1000001]={false};
	for(int i=2;i<1001;i++)
	{
		if(!isPrime[i])
			for(int j=i*i ;j<1000001;j+=i)
				isPrime[j] = true;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;bool a[1000001]={false};
		scanf("%d",&n);
		for(int i=n;i>=2;i--)
		{
			if(isPrime[i] && !a[i])
			{
				int k = sqrt(i);
				for(int j=2;j<=k;j++)
				{
					if(i%j == 0){
						a[j] = true;
						a[i/j]=true;}
				}
			}
		}
		int cnt = 0;
		for(int i=2;i<=n;i++)
			if(!a[i]) cnt++; 
		printf("%d\n",cnt);
	}
	return 0;
}
