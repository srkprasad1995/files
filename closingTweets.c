#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,k,i=0,count=0,a[1000][1000]={{0}};
	scanf("%d %d",&n,&k);
	while(k--)
	{
		char str[10];int key;
		scanf("%s",str);
		if(!strcmp(str,"CLOSEALL"))
		{
			count=0;
			i++;
		}
		else 
		{
			scanf("%d",&key);
			a[i][key]=(a[i][key]+1)%2;
			if(a[i][key]==0)
				count--;
			else count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
