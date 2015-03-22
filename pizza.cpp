#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n;int a[4] = {0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int arr,b;char ch;
		cin >> arr>>ch>>b;
		if(arr==3)
			a[2]++;
		else if(b == 2)
			a[1]++;
		else if(b==4) a[0]++;
	}
	int ans=a[2];
	a[0] = a[0] - a[2];
	ans += a[1]/2;
	a[1] = a[1]%2;
	if(a[1] == 1)
	{
		ans ++;
		a[0] -= 2;
	}
	if(a[0]>0)
	{
		ans += a[0]/4;
		if(a[0] %4 >0)
			ans ++;
	}
	printf("%d\n",ans+1);
	return 0;
}
