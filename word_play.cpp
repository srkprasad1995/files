#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<cstring>

using namespace std;

int a[26][26];
int A[26];
int B[26];
int visited[26];

void DFS( int n )
{
	visited[n] = 1;
	for( int i =0 ; i < 26 ;i++ )
		if( a[n][i] && !visited[i])
			DFS(i);
	return;
}

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--)
	{	
		int n;
		scanf("%d" , &n);
		memset (  a , 0 , sizeof(a));
		memset ( A , 0 , sizeof(A));
		memset (B ,0, sizeof(B));
		memset(visited , 0 , sizeof(visited));
		for( int k = 0 ;k < n ;k++)
		{
			char p,q,ch;
			p = getchar_unlocked();
			ch = q = p;
			while(ch!='\n') {
				q=ch;
				ch=getchar_unlocked();
			}
 
			p=p-'a';
			q=q-'a';
			if(p!=q) {
				a[p][q]=1;
				a[q][p]=1;
			}
			A[p]++;
			B[q]++;
 
		}
		int cnt1 = 0;
		int cnt2 = 0;
		int index = 26;
		for(int i=0 ; i < 26 ; i ++ )
		{
			if( A[i] == B[i])
				continue;
			if( A[i] == B[i] + 1)
				cnt1 ++;
			else if ( B[i] == A[i] + 1)
				cnt2 ++;
			else{
				index = i ; break; }
		}
		if( index < 26 || !( cnt1 == cnt2  &&  cnt1 <= 1))
		{
			printf("The door connot be opened.\n");
			continue;
		}
		int cnt = 0;
		for(int i=0 ;i < 26 ;i ++)
		{
			if( (A[i] > 0 || B[i] >0 ) && !visited[i])
			{
				cnt ++;
				if ( cnt == 2)
					break;
				DFS ( i );
			}
		}
		if(cnt == 2)
			printf("The door connot be opened.\n");
		else printf("Ordering is possible.\n");
	}
	return 0;
}
