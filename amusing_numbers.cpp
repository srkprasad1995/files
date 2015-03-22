#include<iostream>
#include<cstdio>
#include<cstring>
 
char *strrev(char str[])
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main()
{
int t;
scanf("%d",&t);
while(t--){  long long n; 
  scanf("%lld", &n);
 n++;
 char str[100];
memset(str,0,sizeof(str));
int  c=0;
while(n>0)
  {
    if (n & 1)
	str[c++]='6';
    else
	str[c++]='5';

n = n >> 1;
  }
int l=strlen(str);
str[l-1]='\0';
strrev(str);
printf("%s",str);
 
  printf("\n");
 }
  return 0;
}
