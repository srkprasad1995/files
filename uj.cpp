#include<iostream>
#include<cstdio>
int main(){while(true){int n,d;scanf("%d %d",&n,&d);if(n==0 && d==0) break;if(d==0){printf("1\n");continue;}if(n==1){printf("1\n");continue;}int a[1000001]={0};int n1=n;int k=0;while(n1){ a[k++]=n1%10;n1/=10;}for(int i=1;i<d;i++){int prod,temp=0;for( int j = 0 ; j<k ; j++){prod =a[j]*n + temp;a[j] = prod % 10;temp =prod /10;}while(temp){a[k++] = temp%10;temp = temp/10;}}for(int i=k-1;i>=0;i--)printf("%d",a[i]);printf("\n");}return 0;}
