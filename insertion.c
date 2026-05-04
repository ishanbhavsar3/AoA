#include <stdio.h>
int main()
{
	printf("Input number of array elements: ");
	int n, i, j, temp, a[20];
	scanf("%d", &n);
	printf("Input %d array elements: ", n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0; i<n; i++)
	{
		temp=a[i]; j=i-1;
		while(j>=0&&temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("Sorted array using Insertion sort is: ");
	for(i=0; i<n; i++)
	{
		 printf("%d ", a[i]);
	}
	
}
