#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int f = 0,sum,cnt=0,visited[1000]={0};
	scanf("%d",&sum);
	while(sum!=1)
	{
		int temp=0;cnt++;
		while(sum)
		{
			int k=sum%10;
			temp += k*k;
			sum=sum/10;
		}
		sum=temp;
		if(visited[sum])
		{
			f=1;
			break;
		}
		visited[temp] = 1;
	}
	if(f) printf("-1\n");
	else printf("%d\n",cnt);
	return 0;
}
