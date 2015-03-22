#include<stdio.h>
# define MAX 100
int c=0,a[MAX][MAX]={0};
int main()
{
    int n,m,k,l,i,j,x=0,y;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&k,&l);
        a[k][l]=1;
    }
    for(j=1;j<=n;j++)
    {
        if(a[1][j]==1)
        {
            x=check(1,j,n);
            if (x<999)
            y=x;    
        }
    }
printf("%d",y);
return 0;
}
int check(int i,int j,int n)
{       
    a[i][j]=0;
    if(j==n)
    return c;
    else 
    {       
        for(j=1;j<=n;j++)
        {
            if(a[i+1][j]==1)            
            {    
                check(i+1,j,n);
            }
        }
        else 
        {
            for(i=1;i<=n;i++)
            {
                if(a[i][j]==1)
                {
                    c++;
                                    check(i,j,n);                        
                }
            }                            
        else 
        {printf("-1");        
        }        
    }
}
