#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

typedef struct node
{
	int w,b,h;
}node;

int compare(node a,node c)
{
	return ((a.b*a.w)>(c.b*c.w));
}

int main()
{
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(n == 0) break;
		node box[91];
		for(int i=0;i<n;i++)
		{
			int p,q,r;
			scanf("%d %d %d",&p,&q,&r);
			if(p>q) box[3*i].w=p,box[3*i].b=q,box[3*i].h=r;
			else box[3*i].w=q,box[3*i].b=p,box[3*i].h=r;
			if(p>r) box[3*i+1].w=p,box[3*i+1].b=r,box[3*i+1].h=q;
			else box[3*i+1].w=r,box[3*i+1].b=p,box[3*i+1].h=q;
			if(q>r) box[3*i+2].w=q,box[3*i+2].b=r,box[3*i+2].h=p;
			else box[3*i+2].w=r,box[3*i+2].b=q,box[3*i+2].h=p;
		}
		sort(box,box+3*n,compare);
		int h[91];
		h[0] = box[0].h;
		for(int i=1;i<3*n;i++)
		{
			h[i] = box[i].h;
			for(int j=0;j<i;j++)
			{
				if((box[i].w<box[j].w) && (box[i].b<box[j].b))
					h[i] = max(h[i],h[j]+box[i].h);
			}
		}
		int max=h[0];
		for(int i=1;i<3*n;i++)
			max = h[i]>max ? h[i]:max;
		printf("%d\n",max);
	}
	return 0;
}
