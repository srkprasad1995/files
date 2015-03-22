#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,k,i=0,count=0,a[1000]={0};
	scanf("%d %d",&n,&k);
	while(k--)
	{
		char str[10];int key;
		scanf("%s",str);
		if(strlen(str)<=5)
		{
			scanf("%d",&key);
			if(a[key]==0)
			{
				a[key]++;
				count++;
			}
			else{ a[key]--;count--;}
		}
		else
		{
			count=0;
			memset(a,0,sizeof(a));
		}
		printf("%d\n",count);
	}
	return 0;
}

