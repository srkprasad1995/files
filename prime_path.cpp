#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>

using namespace std;

bool isPrime[10009];
void seive()
{
	for(int i=2;i<=100;i++)
	{
		if(!isPrime[i])
		{
			for(int j=i*i;j<=10000;j+=i)
				isPrime[j] = true;
		}
	}
}

int into_num(int a[])
{
	int num=0;
	for(int i=0;i<4;i++)
	{
		num = num*10 +a[i];
	}
	return num;
}

void into_arr(int a[],int num)
{
	int k=3;
	while(num)
	{
		a[k] = num%10;
		num /= 10;
		k--;
	}
}

int main()
{
	int t;
	seive();
	scanf("%d",&t);
	while(t--)
	{
		int n,m,arr[4];
		scanf("%d %d",&n,&m);
		queue<int > q;
		int dist[10009];
		memset(dist,-1,sizeof(dist));
		q.push(n);dist[n] = 0;
		int f=1;
		if(n==m) f=0;
		while(!q.empty()&&f)
		{
			int num = q.front();
			q.pop();
			for(int k=0;k<4&&f;k++)
			{
				into_arr(arr,num);
				for(int i=0;i<10&&f;i++)
				{
					arr[k] = i;
					int temp = into_num(arr);
					if(dist[temp]==-1&&temp>=1000&&!isPrime[temp])
					{
						dist[temp]=dist[num]+1;
						q.push(temp);
					}
					if(temp == m)
						f=0;
				}
			}
		}
		if(dist[m] == -1)
			puts("Impossible");
		else printf("%d\n",dist[m]);
	}
	return 0;
}
