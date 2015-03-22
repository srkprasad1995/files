#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	int n1,n2;
	while(true)
	{		
		int i,j;
		scanf("%d",&n1);
		if(n1 ==0)
			break;
		int a1[10000],a2[10000];
		for(i=0;i<n1;i++)
			scanf("%d",&a1[i]);		
		scanf("%d",&n2);
		for(i=0;i<n2;i++)
			scanf("%d",&a2[i]);
		int b1[10000],b2[10000],k=0,sum1[10000]={0},sum2[10000]={0};
		b1[k] = 0;b2[k] = 0;k++;i=0;j=0;
		while(i<n1 && j<n2)
		{
			if(a1[i]<a2[j])
				i++;
			else if(a1[i] > a2[j])
				j++;
			else
			{
				b1[k]=i;
				b2[k]=j;
				i++;j++;k++;
			}
		}
		b1[k]=n1;
		b2[k]=n2;
		for(i=0;i<k;i++)
		{
			for(j=b1[i];j<b1[i+1];j++)
				sum1[i]+=a1[j];
			for(j=b2[i];j<b2[i+1];j++)
				sum2[i]+=a2[j];
		}
		int sum=0;
		for(i=0;i<k;i++)
		{
			sum += sum1[i]>sum2[i]?sum1[i]:sum2[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
