#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m,n,r=0,a[100001];
	scanf("%d %d",&n ,&m);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(m--)
	{
		int key;
		char ch[2];
		scanf("%s %d" ,ch ,&key);
		if(ch[0]== 'R')
		{
			int temp,x=key+r-1;
			temp=(((x < 0) ? ((x % n) + n) : x) % n);
			printf("%d\n",a[temp]);
		}
		else if(ch[0] == 'C')
			r += key;
		else r -= key;
	}
	return 0;
}
