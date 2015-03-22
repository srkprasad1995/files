#include<stdio.h>

int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int n,m,d;
scanf("%d %d",&n,&m);
int p[200001];
int i,j,k=0;
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
int b[200001][3],c[200001][3],visited[100001]={0};
for(i=1;i<=n;i++)
{
if(visited[i]==0){
c[k][0]=i;
j=i;
while(p[j]!=i)
{
visited[i]++;
d=j;
j=p[j];
}
c[k][1]=d;
k++;
}
}
for(i=0;i<k;i++)
printf("%d %d\n",c[i][0],c[i][1]);
}
return 0;
}
