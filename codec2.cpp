#include<iostream>
#include<algorithm>
using namespace std;
#include<cstdio>
#include<string.h>
#include<math.h> 

int gcd_util(int a,int b)
{
	if(b == 0)
		return a;
	else 
		return gcd_util(b,a%b);
}

int gcd(int a,int b)
{
	return a>b ? gcd_util(a,b):gcd_util(b,a);
}


 
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q,arr[100001],left[100001],right[100001];
		scanf("%d %d",&n,&q);
		for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
		left[0] = arr[0];
		for(int i=1;i<n;i++)
			left[i] = gcd(left[i-1],arr[i]);
		right[n-1] = arr[n-1];
		for(int i = n-2;i>=0 ; i--)
			right[i] = gcd(right[i+1],arr[i]);
		while(q--)
		{
			int p,q;
			scanf("%d %d",&p,&q);p--;q--;
			int q1 = (p>0) ? left[p-1] :0;
			int q2 = (q<(n-1))? right[q+1] :0;
			cout << gcd(q1,q2) << endl; 
		}
	}
	return 0;
}
