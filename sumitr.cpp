#define s(n) scanf("%d",&n)
#define f(i,n) for(i=0;i<n;i++)
main(){int t,i,j,n,a[100][100];s(t);while(t--){s(n);f(i,n)f(j,i+1)s(a[i][j]);for(i=n-1;i>=0;i--)f(j,i+1)a[i][j]+=a[i+1][j]>a[i+1][j+1]?a[i+1][j]:a[i+1][j+1];printf("%d\n",a[0][0]);}}
