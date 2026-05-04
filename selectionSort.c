#include <stdio.h>
int main()
{
	int i, n, j, min, a[100], temp;
	printf("Input number of array elements: ");
	scanf("%d", &n);
	printf("Input array elements: ");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	printf("Sorted array using selectionSort is: ");
	for(i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}

