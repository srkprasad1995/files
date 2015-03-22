#include<cstdio>
#include<iostream>
#include<cmath>
#include<stack>
#include<cstring>

using namespace std;

char str[350001];
int  a[350001];
int b[350001];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		stack<int > s;
		int l = strlen(str);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int cnt=0;
		for(int i=0;i<l;i++)
		{
			if(str[i] == '(')
			{
				s.push(i);
				cnt++;
			}
			else
			{
				int k = s.top();
				a[k] = i;
				s.pop();
			}
		}
		for(int i=0;i<l;i++)
		{
			int cnt = 0;
			if(str[i] == '(')
			{
				for(int j=i+1;j<a[i];j++)
				{
					if(str[j] == '(')
						cnt++ ;
					else cnt--;
					b[i] = max(b[i],cnt);
				}
			}
		}
		long long area = 0;bool c=0;
		for(int i=0;i<l;i++)	
		{
			if(str[i] == '(')
			{
				if(c==0) area += (a[i]-i)*(b[i]+1);
				else area -= (a[i]-i)*(b[i]+1);
				s.push(i);
			}
			else s.pop();
			c = !c;
		}
		printf("%lld\n",area);
	}
	return 0;
}
