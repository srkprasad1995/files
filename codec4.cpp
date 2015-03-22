#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef struct node
{
	int a,b;
}node;

bool myfunction(node start,node end)
{
	return (start.b==end.b)?(start.a<end.a):(start.b<end.b);
}

int p_max(node job[], int n)
{
    int i=0, j,cnt=1;
    for (j = 1; j < n; j++)
    {
      if (job[j].a > job[i].b)
      {
	  cnt ++;
          i = j;
      }
    }
    return cnt;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		node job[100001];int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d %d",&job[i].a,&job[i].b);
		sort(job,job+n,myfunction);
		printf("%d\n",p_max(job,n));
	}
	return 0;
}
