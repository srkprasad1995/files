#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,p,k,sum;
        scanf("%d%d",&n,&k);
        int a[1001];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        p=pow(2,n);
	int max=k;
        for(i=1;i<p;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
                if(i&(1<<j))
                sum ^= a[j];
            if((sum^k) > max)
            {
		max=sum^k;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
