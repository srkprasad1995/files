#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
#define pii pair<int, int>
#define pip pair<int, pii>

vector <pip> graph;
int n,m;
long long T;

const int MAX = 1001;
//class implementing Union Find Data Structure with Path Compression
class Union_Find
{
  public:
 
	int id[MAX], sz[MAX];
	Union_Find(int n)	//class constructor
	{
		for (int i = 0; i < n; ++i)
		{
			id[i] = i;
			sz[i] = 1;
		}
	}
	
	int root(int i)
	{
		while(i != id[i])
		{
			id[i] = id[id[i]];	//path Compression
			i = id[i];
		}
		return i;
	}
	int find(int p, int q)
	{
		return root(p)==root(q);
	}
	void unite(int p, int q)
	{
		int i = root(p);
		int j = root(q);
 
		if(sz[i] < sz[j])
		{
			id[i] = j;
			sz[j] += sz[i];
		}
		else
		{
			id[j] = i;
			sz[i] += sz[j];
		}
	}
};

void kruskal()
{
	Union_Find UF(n);
	int u,v;
	for(int i=0;i<m;i++)
	{
		u=graph[i].second.first;
		v=graph[i].second.second;
		if(!UF.find(u,v))
		{
			UF.unite(u,v);
			T += graph[i].first;
		}
	}
}
			


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p,a,b,c;
		scanf("%d %d %d",&p,&n,&m);
		graph.resize(m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			a--;b--;
			graph[i] = pip(c,pii(a,b));
		}
		sort(graph.begin(),graph.end());
		T=0;
		kruskal();
		printf("%lld\n", T*p);
	}
	return 0;
}
