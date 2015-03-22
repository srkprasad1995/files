#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;

int max(int w,int x,int y,int z)
{
	int max = -1;
	if(x>max)
		max=x;
	if(y>max)
		max=y;
	if(z>max)
		max=z;
	if(w>max)
		max=w;
	return max;
}

int main()
{
	while(true)
	{
		int w,x,y,z,w1,x1,y1,z1;
		scanf("%d%d%d%d%d%d%d%d",&w,&x,&y,&z,&w1,&x1,&y1,&z1);
		if( w+x+y+z+w1+x1+y1+z1==-8)
			break;
		if(w+x+y+z==0)
			printf("0 0 0 0\n");
		else {
			int maxi=INT_MIN;
			int cx,cy,cz,cw;
			cw=w/w1+(w%w1!=0);
			cx = x/x1+(x%x1!=0);
			cy=y/y1+(y%y1!=0);
			cz=z/z1+(z%z1!=0);
			maxi = max(cw,cx,cy,cz);
			x=x1*maxi - x;
			y=y1*maxi-y;
			z=z1*maxi - z;
			w=w1*maxi -w;
			printf("%d %d %d %d\n",w,x,y,z);
		}
	}
	return 0;
}
