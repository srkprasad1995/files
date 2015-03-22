#include<iostream>
#include<cstdio>
#include<algorithm>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[1000001];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int cnt=0,max_id=0;
		for(int i=1;i<n;i++)
		{
			if(a[i] == a[max_id])
				cnt ++;
			else cnt --;
			if(cnt == 0)
				max_id = i,cnt=1;
		}
		cnt=0;
		for(int i=0;i<n;i++)
			if(a[max_id] == a[i])
				cnt++;
		if(cnt <= (n/2))
			printf("NO\n");
		else printf("YES %d\n",a[max_id]);
	}
	return 0;
}
