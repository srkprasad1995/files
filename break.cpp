#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool visited[1000];

int main()
{
	int t = 32;
	while(t--)
	{
		char str[12];int k;
		memset(visited , 0 , sizeof(visited));
		scanf("%d",&k);
		int sum=k,cnt=0;
		while(sum != 1)
		{
			int sum1 = 0;
			cnt ++;
			while(sum)
			{
				int temp = sum%10;
				sum1 += temp * temp;
				sum = sum/10;
			}
			if(visited[sum1])
				break;
			sum = sum1;
			visited[sum]= true;
		}
		if( sum == 1)
			printf("%d\n",cnt);
		else printf("-1\n");
	}
	return 0;
}
