#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

#define M 5000002
#define mod  1000000007

bool isP[M+1];
int P[M+1];
long long perm[M+1];

#define getcx getchar_unlocked
#define putcx putchar_unlocked

inline void readInt( int &n ) {
    n=0;
    int ch=getcx();
    while( ch < '0' || ch > '9' ){ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
 
inline void writeInt(int n) {
	int i = 10;
	char buf[11];
	buf[10] = '\n';
	
	while (n) {
		buf[--i] = n % 10 + '0';
		n /= 10;
	}
	
	do {
		putcx(buf[i]);
	} while (buf[i++] != '\n');
}
 
 

int main()
{
	memset( isP , true , sizeof(isP));
	isP[0] = isP[1] = 0;
	for( int i = 2 ; i * i < M ;i ++)
	{
		if(isP[i])
			for( int  j = i*i ; j < M ; j +=i)
				isP[j] = 0;
	}
	P[1] = 1;
	for( int i = 2;i <M ;i ++)
		P[i] = P[i-1] + isP[i];
	perm[1] = 1;
	for(int i = 2 ; i < M ;i ++)
		 perm[i] = (((perm[i-1])%mod) * ((P[i])%mod)) % mod;
	int t;
	readInt(t);
	while(t--)
	{
		int n;
		readInt(n);
		printf("%lld\n",perm[n]);
	}
	return 0;
}
