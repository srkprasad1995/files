#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,G;
		scanf("%d %d",&n,&G);
		int city[100001];
		bool general[50001];
		for(int i=1;i<=G;i++)
			cin >> general[i];
		int query;
		scanf("%d",&query);
		memset(city,-1,sizeof(city));
		for(int i=0;i<query;i++)
		{
			int p;
			cin >> p;
			if(p==1)
			{
				char option;
				int a,b;
				cin >> option ;
				cin >> a >> b;
				if(option == 'g')
					city[b] = a;
				else city[b] = city[a];
			}
			else if(p==2)
			{
				int a;
				scanf("%d",&a);
				if(city[a] == -1)
					printf("Free\n");
				else if(general[city[a]] == 1)
					printf("Dukkar\n");
				else
					printf("Mathur\n");
			}
			else
			{
				int a;
				scanf("%d",&a);
				general[a] = !general[a];
			}
		}
	}
	return 0;
}
