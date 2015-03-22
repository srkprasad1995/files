#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

vector <int > arr[100001];

int mini(int a,int b)
{
	return a<b?a:b;
}


int revers(int n, int m,int visited[],int temp,int temp1)
{
	int i;
	if(n==1){
	int j=0;
		for(i=0;i<arr[1].size();i++)
			if(arr[1][i]==1)
				return 0;
		return -1;
	}
	if(temp==n)
		return 0;
	if(temp1>100001)
		return -1;
	int min=100002;
	for(i=0;i<arr[temp].size();i++)
	{
		visited[temp]=1;
		if(!visited[arr[temp][i]]&&(temp!=arr[temp][i]))
		{
			if(arr[temp][i]<0)
			{
				int b=revers(n,m,visited,(-arr[temp][i]),temp1+1);
				if(b!=-1)
				{
					min=mini(min,1+b);
				}
			}
			else
			{
				int b=revers(n,m,visited,arr[temp][i],temp1+1);
				if(b!=-1)
				{
					min=mini(min,b);
				}
			}
		}
	}
printf("%d\n",min);
if(min==100002)
return -1;
return min;
}

int main()
{
	int n ,m,a,b,i,visited[100001]={0},temp=1,temp1=0;
	scanf("%d %d",  &n , &m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d", &a , &b );
		arr[a].push_back(b);
		arr[b].push_back(-a);
	}
	printf("%d\n",revers(n ,m,visited,temp,temp1));
	return 0;
}


