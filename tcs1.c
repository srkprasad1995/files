#include<stdio.h>
#include<stdlib.h>

int cmpr(const void *a,const void *b)
{
return *(int *)a- *(int *)b;
}

int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int n,t,E[51],p,d;
		scanf("%d %d",&n,&t);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&E[i]);
		scanf("%d %d",&p,&d);
		//if(n>t+1){if(k==0) printf("No");
		//	else printf("No\n");}
		//else
		//{
			qsort(E,n,sizeof(int),cmpr);int f=0;
			for(i=0;i<t;i++)
			{
				if(p<E[i]){f=1;break;}
				else
				{
					p+=p-E[i];
				}
			}
			if(f==0&&p>=d){
					if(k==0) printf("Yes");
					else printf("Yes\n");}
			else {
					if(k==0) printf("No");
					else printf("No\n");break ;}
		//}
	}
	return 0;
}
