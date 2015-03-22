#include<stdio.h>
#include<math.h>
int rev(int ,int );
int main()
{
int a=54321;
int n=5;
a=rev(a,n);
return 0;
}

int rev(int a,int n)
{
int temp;
if(a<=0)
return 0;
else{ 
temp=a%10;
a/=10;
a=rev(a,n-1);
a=((int )pow(10,n-1))*temp+a;
return a;
}
return 0;
}


