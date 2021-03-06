#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <set>

using namespace std;

#define MX 31
#define MXV 1010

vector<int> poss[MX];
bool vis[MXV];

void pre()
{
	poss[0].push_back(0);
	poss[1].push_back(2);

	for(int n=2;n<MX;n++)
	{
		memset(vis,false,sizeof vis);

		for(int i=0,j=n-1-i;i<=j;i++,j--)
		{
			for(vector<int>::iterator it = poss[i].begin(); it != poss[i].end(); it++)
				for(vector<int>::iterator jt = poss[j].begin(); jt != poss[j].end(); jt++)
					vis[*it+*jt+n+1] = true;
		}
	
		for(int i=1;i<MXV;i++) if(vis[i]) poss[n].push_back(i);
	}
}

int main()
{
	pre();
	int t, n, m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		int ans = -1;
		for(vector<int>::iterator it = poss[n].begin(); it!=poss[n].end(); it++)
			if(*it<=m) ans = m - *it;
		printf("%d\n",ans);
	}
	return 0;
}
