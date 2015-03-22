#include <stdio.h>
 
int min(int x, int y) { return (x < y)? x :y; }
 
// The function that handles duplicates.  It can be O(n) in worst case.
int findMin(int arr[], int low, int high)
{
	if(high<low)
		return arr[0];
	if(high==low)
		return arr[low];
	int mid=(high+low)/2;
	if(mid < high && arr[mid+1]<arr[mid])
		return arr[mid+1];
	if(arr[low]==arr[mid]  && arr[mid]==arr[high])
		return min(findMin(arr,low,mid-1),findMin(arr,mid+1,high));
	if(mid>low&& arr[mid]<arr[mid-1])
		return arr[mid];
	if(arr[mid] > arr[high])
		return findMin(arr,mid+1,high);
	return findMin(arr,low,mid-1);
}
 
// Driver program to test above functions
int main()
{
    int arr1[] =  {5, 6, 1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("The minimum element is %d\n", findMin(arr1, 0, n1-1));
 
    int arr2[] =  {1, 1, 0, 1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("The minimum element is %d\n", findMin(arr2, 0, n2-1));
 
    int arr3[] =  {1, 1, 2, 2, 3};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("The minimum element is %d\n", findMin(arr3, 0, n3-1));
 
    int arr4[] =  {3, 3, 3, 4, 4, 4, 4, 5, 3, 3};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    printf("The minimum element is %d\n", findMin(arr4, 0, n4-1));
 
    int arr5[] =  {2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    printf("The minimum element is %d\n", findMin(arr5, 0, n5-1));
 
    int arr6[] =  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    printf("The minimum element is %d\n", findMin(arr6, 0, n6-1));
 
    int arr7[] =  {2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    printf("The minimum element is %d\n", findMin(arr7, 0, n7-1));
 
    return 0;
}
