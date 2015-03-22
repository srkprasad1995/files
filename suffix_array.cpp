#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

char str[50005];
int s[50005];

int cmp(const void *a,const void *b) {
	return (strcmp((str+ *((int*)a)),(str+ *((int*)b))));
}


void suffix_arr(int l)
{
	for(int i=0;i<l;i++)
		s[i] = i;
	qsort(s,l,sizeof(int),cmp);
	return ;
}

long long lcp(int l)
{
	char *x=str,*y=str;
	long long cnt=0;
	for(int i=1;i<l;i++)
	{
		x=str+s[i];
		y=str+s[i-1];
		while(*x==*y)
		{
			x++;
			y++;
			cnt++;
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
		scanf("%s",str);
		long long l=strlen(str);
		suffix_arr(l);
		long long c=lcp(l);
		printf("%lld\n",l*(l+1)/2 -c);
	}
	return 0;
}
