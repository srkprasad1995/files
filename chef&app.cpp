#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;bool visited[100001]={0};
		scanf("%d",&n);
		int cnt=0;
		while(n--)
		{
			int temp;
			scanf("%d",&temp);
			if(!visited[temp])
			{
				cnt++;
				visited[temp] = true;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
