#include<stdio.h>
#include<limits.h>


int maxSubArraySum(int a[], int size)
{
	int maxsum=INT_MIN,sum=0;
	int j;
	for(j=0;j<size;j++)
	{
		sum += a[j];
		if(sum > maxsum)
			maxsum = sum;
		else if(sum<0)
			sum=0;
	}
	return maxsum;
} 
 
/*Driver program to test maxSubArraySum*/
int main()
{
   int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   getchar();
   return 0;
}

