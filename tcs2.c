#include <stdio.h>
 
#define M 350
 
int maze[M][M], n;int test[M][M]={{0}};
 
int path(int i, int j,int x,int y){
     int f=0;
    if(i == x && j == y)
        return 1;
    test[i][j]=1;
    if((j + 1) <= n &&test[i][j+1]==0&& maze[i][j + 1] == 0)
       if( path(i, j + 1,x,y)==1); f=1;
    if((i + 1) <= n &&test[i+1][j]==0&&  maze[i + 1][j] == 0)
      if (path(i + 1, j,x,y)==1) f=1;
    if((j - 1) >= 1 &&test[i][j-1]==0&&  maze[i][j - 1] == 0)
      if  (path(i, j - 1,x,y)==1) f=1;
    if((i - 1) >= 1 && test[i-1][j]==0&& maze[i - 1][j] == 0)
       if( path(i - 1, j,x,y)==1) f=1;
    test[i][j]=0;
    if(f==1) return 1;
    return 0;
}

int main(){
    int i, j,r,n;int b[122501][2];
    scanf("%d", &n);char ch[3];
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
		scanf("%s",ch);
		if(ch[0]=='O') maze[i][j]=0;
		else maze[i][j]=1;
        }
    }
    scanf("%d",&r);
    for(i=1;i<=r;i++)
     {
		scanf("%d %d",&b[i][0],&b[i][1]);
     }
      int f=0;
    for(i=2;i<=r;i++)
     {
		if(path(b[1][0],b[1][1],b[i][0],b[i][1])==0)
		f=1;
     }
	if(f==0)
	printf("Yes");
        else printf("No");
    return 0;
}
