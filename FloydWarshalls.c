#include <stdio.h>
int main()
{
	int i, j, k, n, d[100][100];
	printf("Input n: ");
	scanf("%d", &n);
	printf("Input matrix of %d*%d size: ", n, n);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{	
			scanf("%d", &d[i][j]);
		}
	}
	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{	
				if(d[i][k]+d[k][j]<d[i][j])
					d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	printf("Final matrix of %d*%d size:\n", n, n);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{	
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}	
}
