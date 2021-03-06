#include<stdio.h>
#include<stdbool.h>
#include<string.h>
 
// This function returns true if contents of arr1[] and arr2[]
// are same, otherwise false.
bool compare(int arr1[], int arr2[])
{
	int i;
	for(i=0;i<256;i++)
		if(arr1[i] != arr2[i])
			return false;
	return true;
}

void search(char path[],char text[])
{
	int countP[256]={0};
	int countT[256]={0};
	int lP=strlen(path);
	int tP=strlen(text);
	int i;
	for(i=0;i<lP;i++)
	{
		countP[path[i]]++;
		countT[text[i]]++;
	}
	for(i=lP;i<tP;i++)
	{
		if(compare(countP,countT))
			printf("%d  ",i-lP);
		countT[text[i]]++;
		countT[text[i-lP]]--;
	}
	if(compare(countP,countT))
		printf("%d\n",tP-lP);
	return ;
}
 
/* Driver program to test above function */
int main()
{
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    search(pat, txt);
    return 0;
}

