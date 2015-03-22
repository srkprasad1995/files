#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int queue_array[100001];
int rear = - 1;
int front = - 1;
vector<int > v[100001];
int dist[100001];
void enque(int add_item)
{
        if (front == - 1)
        front = 0;
        rear = rear + 1;
        queue_array[rear] = add_item;
}

int deque()
{
	int temp=queue_array[front];
        front = front + 1;
	return temp;
}

int isemptyq()
{
    if (front == - 1 || front > rear)
    {
        return 1;
    }
	return 0;
}

int main()
{
	int n,m,u;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(-x);
	}
	enque(1);
	int i,d;
	for(i=1;i<=n;i++)
	{
		dist[i]=-1;
	}
	dist[1]=0;
	while(!isemptyq())
	{
		u=deque();
		for(i=0;i<v[u].size();i++){
			if(v[u][i]>0)
			{
				d=dist[u];
			if(dist[v[u][i]]==-1)
			{
				dist[v[u][i]]=d;
				enque(v[u][i]);//printf("%dt %d\n",v[u][i],d);
			}
			if(dist[v[u][i]]>d)
			{
				dist[v[u][i]]=d;
				enque(v[u][i]);//printf("%dt %d\n",v[u][i],d);
			}}
			else{
				//printf("%d",v[u][i]);
				d=dist[u]+1;
			if(dist[-v[u][i]]==-1)
			{
				dist[-v[u][i]]=d;
				enque(-v[u][i]);//printf("%d %d\n",v[u][i],d);
			}
			if(dist[-v[u][i]]>d)
			{
				dist[-v[u][i]]=d;
				enque(-v[u][i]);//printf("%d %d\n",v[u][i],d);
			}}
		}
	}
	printf("%d\n",dist[n]);
	return 0;
}
