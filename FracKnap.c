#include <stdio.h>
int main(){
	int i, j, n, w[100], v[100], cap, t;
	float r[100], tr, profit=0;

	printf("Input number of items: ");
	scanf("%d", &n);

	printf("Enter capacity of knapsack: ");
	scanf("%d", &cap);

	printf("Enter weights and values of items:\n");
	for(i=0; i<n; i++){
		scanf("%d %d", &w[i], &v[i]);
	}

	// ratio
	for(i=0; i<n; i++)
		r[i] = (float)v[i]/w[i];

	// 🔹 ORIGINAL TABLE
	printf("\n--- Original Table ---\n");
	printf("Item\tW\tV\tRatio\n");
	for(i=0; i<n; i++)
		printf("%d\t%d\t%d\t%.2f\n", i+1, w[i], v[i], r[i]);

	// sorting
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(r[i] < r[j]){
				tr=r[i]; r[i]=r[j]; r[j]=tr;
				t=w[i]; w[i]=w[j]; w[j]=t;
				t=v[i]; v[i]=v[j]; v[j]=t;
			}
		}
	}

	// 🔹 SORTED TABLE
	printf("\n--- Sorted Table (by ratio) ---\n");
	printf("Item\tW\tV\tRatio\n");
	for(i=0; i<n; i++)
		printf("%d\t%d\t%d\t%.2f\n", i+1, w[i], v[i], r[i]);

	// 🔹 SELECTION PROCESS
	printf("\n--- Selection Steps ---\n");
	printf("Item\tTaken\tRemaining Cap\tProfit\n");

	for(i=0; i<n; i++){
		if(cap >= w[i]){
			cap -= w[i];
			profit += v[i];
			printf("%d\tFull\t%d\t\t%.2f\n", i+1, cap, profit);
		}
		else{
			float frac = (float)cap / w[i];
			profit += v[i]*frac;
			printf("%d\t%.2f\t0\t\t%.2f\n", i+1, frac, profit);
			break;
		}
	}

	printf("\nMax Profit = %.2f", profit);
}