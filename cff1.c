#include<stdio.h>
void merge(int [],int ,int ,int );
void part(int [],int ,int );
int main()
{
 int t;
scanf("%d",&t);
while(t--)
{
int n,m;
scanf("%d %d",&n,&m);
int p[200001];
int i;
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
int b[200001][3];
for(i=0;i<m;i++)
{
scanf("%d %d",&b[i][0],&b[i][1]);
}
int c=2;
while(c--)
{
for(i=0;i<m;i++)
part(p,b[i][0],b[i][1]);
}
for(i=1;i<=n;i++)
if(p[i]!=i)
break;
if(i==n+1)
printf("Possible\n");
else printf("Impossible\n");
}
return 0;
}


void part(int arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid);
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void merge(int arr[],int min,int mid,int max)
{
  int tmp[30];
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}
