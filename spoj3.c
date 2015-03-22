#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define size 401

char s[size];
int top=-1;

void push(char elem)
{
	s[++top]=elem;
}

char pop()
{
	char temp=s[top];
	top--;
	return temp;
}

int pr(char elem)
{
	switch(elem)
	{
		case '#': return 0;
		case '(': return 1;
		case '+':
		case '-' : return 2;
		case '*': 
		case '/': return 3;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char pofx[401],infx[401];
		scanf("%s",infx);
		push('#');
		char ch;int i=0,k=0;
		while((ch=infx[i++])!='\0')
		{
			if(ch=='(')
				push(ch);
			else if(isalnum(ch))
			{
				pofx[k++]=ch;
			}
			else if(ch== ')')
			{
				while(s[top]!='(')
					pofx[k++]=pop();
				pop();
			}
			else 
			{
				while(pr(s[top])>=pr(ch))
				{
					pofx[k++]=pop();
				}
				push(ch);
			}
		}
		while(s[top]!='#')
			pofx[k++]=pop();
		pofx[k]='\0';
		printf("%s\n",pofx);
	}
	return 0;
}
