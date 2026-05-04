
#include <stdio.h>
void minmax(int a[], int l, int r, int *min, int *max)
{
	if(l==r)
		*min=*max=a[l];
	else
	{
		int min1, max1, min2, max2, mid=(l+r)/2;
		minmax(a, l, mid, &min1, &max1);
		minmax(a, mid+1, r, &min2, &max2);
		*min=min1<min2?min1:min2;
		*max=max1>max2?max1:max2;
	}
}

int main(){
	int l, r, n, i, a[100], min, max;
	printf("Input number of elements: ");
	scanf("%d", &n);
	printf("Input elements of array to get min and max.");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	minmax(a, 0, n-1, &min, &max);
	printf("Min=%d and Max=%d", min, max);
}
