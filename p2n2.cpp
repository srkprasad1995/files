#include <iostream>
#include <assert.h>
using namespace std;
 
// Utility function to right rotate all elements between [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
	int temp=arr[cur];
	int i;
	for(i=cur ; i > outofplace ; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[outofplace]=temp;
}
 
void rearrange(int a[], int n)
{
	int outofplace=-1;
	int index;
	for(index=0 ; index < n ; index++ )
	{
		if(outofplace >= 0)
		{
			if( ( a[index] < 0 &&  a[outofplace]>=0)  ||  ( a[index] >= 0 && a[outofplace] < 0))
			{	
				rightrotate( a , n , outofplace , index );
				if( ( index - outofplace )  > 2)
					outofplace  +=  2;
				else   outofplace  = -1;
			}
		}
		if(outofplace==-1)
		{
			if( ( a[index] >= 0 && ( !(index %2)) ) ||  ( a[index]  < 0 && (index % 2)))
				outofplace  = index;
		}
	}
	return ;		 
}
 
// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test abive function
int main()
{
    //int arr[n] = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
    //int arr[] = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4};
    int arr[] = {5, 3, 4, 2, 1, -2 , -8, -9, -1 , -4,-6,-9,10,-11};
   // int arr[] = {-5, 3, -4, -7, -1, -2 , -8, -9, 1 , -4};
    //int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "Rearranged array is \n";
    printArray(arr, n);
 
    return 0;
}
