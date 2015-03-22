#include<iostream>
#include<vector>

using namespace std;

vector <int > arr[100001];

int main()
{	
	int n ,m,a[100001][2],i,visited[100001]={0},temp=1,temp1=0,j;
	scanf("%d %d",  &n , &m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d", &a[i][0] , &a[i][1] );
		arr[a[i][0]].push_back(a[i][1]);
		arr[a[i][1].push_front(a[i][0]);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d:",i);
		for(j=0;j<arr[i].size();j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	//printf("%d",revers(a ,n ,m,visited,temp,temp1));
	return 0;
}
 
int revers(int a[100001][2], int n, int m,int visited[],int temp,int temp1)
{
	int i;
	if(temp==n)
		return 0;
	if(temp1>n)
		return -1;
	int min=100002;
	for(i=0;i<m;i++)
	{
		visited[temp]++;
		if(a[i][0]==temp)
		{
			if(!visited[a[i][1]])
			{
				int b=revers(a,n,m,visited,a[i][1],temp1+1);
				if(b!=-1)
				min=mini(min,b);
			}
		}
		visited[temp]--;
	}
	for(i=0;i<m;i++)
	{
		visited[temp]++;
		if(a[i][1]==temp)
		{
			if(!visited[a[i][0]])
			{
				int b=revers(a,n,m,visited,a[i][0],temp1+1);
				if(b!=-1)
				min=1+mini(min,b);
			}
		}			
		visited[temp]--;
	}
if(min==100002)
return -1;
return min;
}
 
int mini(int a,int b)
{
	return a<b?a:b;
} 
