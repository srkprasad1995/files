#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;

int main()
{
while(true){
	char str[10000];
	cin.getline(str,10000);
	if(strcmp(str,"*")==0){
		break;}
	else{
		int l=strlen(str),i,k=0;
		while(str[k]==' '&& k<l)
		{
			k++;
		}
		char ch = str[k];
		for(i=k+1;i<l-1;i++)
		{
			if(str[i] == ' '){
				while(str[i]==' ' && i<l) i++;
					if((abs(str[i+1]-ch) != abs('a' - 'A')) && str[i+1] != ch)
						break;}
		}
		if(i==l-1)
			printf("Y\n");
		else printf("N\n");
	}
}
	return 0;
}
