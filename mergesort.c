#include <stdio.h>
int a[100];
void merge(int l, int m, int r)
{
	int i=l, k=l, j=m+1, temp[300];
	while(i<=m&&j<=r)
		temp[k++]=(a[i]<a[j])?a[i++]:a[k++];
	while(i<=m)
		temp[k++]=[i++];
	while(j<=r)
		temp[k++]=[j++];
	for(i=1; i<=r; i++)
		a[i]=temp[i];
}
void mergesort(int l, int r)
{
	int m=(l+r)/2;
	mergesort(l,m);
	mergesort(m+1, r);
	merge(l, m, r);
}
int main(){
	int n, i;
	printf("Input number of elements of array: ");
	scanf("%d", &n);
	printf("Input array: ");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	mergesort(0, n-1);
	printf("Array sorted using merge sort: ");
	for(i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}
