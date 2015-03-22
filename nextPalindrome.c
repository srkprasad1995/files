#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void util(char str[],int );
void gnp(char str[],int );
int all9(char str[],int );

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[1000001];
		scanf("%s",str);
		int l=strlen(str);
		gnp(str,l);
	}
	return 0;
}

int are9(char str[],int l)
{
	int i;
	for(i=0;i<l;i++)
		if(str[i]!='9')
			return 0;
	return 1;
}

void gnp(char str[],int l)
{
	int i;
	if(are9(str,l))
	{
		printf("1");
		for(i=1;i<l;i++)
			printf("0");
		printf("1\n");
		return ;
	}
	else 
		util(str,l);
	return ;
}

void util(char str[],int l)
{
	int mid=l/2;
	int i = mid-1;
	int j =  (l%2)  ?  (mid+1)  :  mid;
	int ls=0;
	while(str[i]==str[j] && i>=0)
	{
		i--;
		j++;
	}
	if(i<0 || (str[i]-'0')<(str[j]-'0'))
		ls=1;
	while(i>=0)
	{
		str[j]=str[i];
		i--;
		j++;
	}
	if(ls)
	{
		int carry=1;
		i=mid-1;
		if(l%2)
		{
			str[mid] += carry;
			carry=(str[mid]-'0')/10;
			str[mid] = ((str[mid]-'0')%10)+'0';
			j=mid+1;
		}
		else j=mid;
		while(i>=0)
		{
			str[i] += carry;
			carry = (str[i]-'0')/10;
			str[i] = ((str[i]-'0')%10)+'0';
			str[j++]=str[i--];
		}
	}
	printf("%s\n",str);
	return ;
}
