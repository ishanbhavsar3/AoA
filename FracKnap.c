#include <stdio.h>

int main(void) {
    int n, capacity;

    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items.\n");
        return 1;
    }

    int object[n], profitArr[n], weight[n];
    float ratio[n];
    int numerator[n], denominator[n];

    for (int i = 0; i < n; i++) {
        object[i] = i + 1;
        printf("Enter profit and weight of object %d: ", i + 1);
        if (scanf("%d %d", &profitArr[i], &weight[i]) != 2 || weight[i] <= 0) {
            printf("Invalid input (weight must be > 0).\n");
            return 1;
        }
        ratio[i] = (float)profitArr[i] / (float)weight[i];
        numerator[i] = 0;
        denominator[i] = 1;
    }

    printf("Enter capacity of knapsack: ");
    if (scanf("%d", &capacity) != 1 || capacity < 0) {
        printf("Invalid capacity.\n");
        return 1;
    }

    // Sort items by profit/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                float tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                int tempP = profitArr[i];
                profitArr[i] = profitArr[j];
                profitArr[j] = tempP;

                int tempW = weight[i];
                weight[i] = weight[j];
                weight[j] = tempW;

                int tempO = object[i];
                object[i] = object[j];
                object[j] = tempO;

                int tempN = numerator[i];
                numerator[i] = numerator[j];
                numerator[j] = tempN;

                int tempD = denominator[i];
                denominator[i] = denominator[j];
                denominator[j] = tempD;
            }
        }
    }

    int remainingWeight = capacity;
    float totalProfit = 0.0f;
    float valueAdded[n];

    printf("\n--------------------------------------------------------------\n");
    printf("Object\tProfit\tWeight\tRatio\tFraction Taken\tProfit Contributed\tRemaining Weight\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (remainingWeight >= weight[i]) {
            numerator[i] = 1;
            denominator[i] = 1;
            valueAdded[i] = (float)profitArr[i];
            totalProfit += valueAdded[i];

            printf("%d\t%d\t%d\t%.2f\t1\t\t%.2f\t\t\t%d - %d = %d\n",
                   object[i], profitArr[i], weight[i], ratio[i],
                   valueAdded[i], remainingWeight, weight[i], remainingWeight - weight[i]);

            remainingWeight -= weight[i];
        } else if (remainingWeight > 0) {
            numerator[i] = remainingWeight;
            denominator[i] = weight[i];
            valueAdded[i] = ((float)numerator[i] / (float)denominator[i]) * (float)profitArr[i];
            totalProfit += valueAdded[i];

            printf("%d\t%d\t%d\t%.2f\t%d/%d\t\t%.2f\t\t\t%d - %d = 0\n",
                   object[i], profitArr[i], weight[i], ratio[i],
                   numerator[i], denominator[i], valueAdded[i],
                   remainingWeight, remainingWeight);

            remainingWeight = 0;
        } else {
            numerator[i] = 0;
            denominator[i] = 1;
            valueAdded[i] = 0.0f;

            printf("%d\t%d\t%d\t%.2f\t0\t\t0.00\t\t\t%d\n",
                   object[i], profitArr[i], weight[i], ratio[i], remainingWeight);
        }
    }

    printf("--------------------------------------------------------------\n");

    printf("X[");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");

        if (numerator[i] == denominator[i]) {
            printf("x%d-1", object[i]);
        } else if (numerator[i] == 0) {
            printf("x%d-0", object[i]);
        } else {
            printf("x%d-%d/%d", object[i], numerator[i], denominator[i]);
        }
    }
    printf("]\n");

    printf("\nKnapsack (Vertical Stack - Weight Taken):\n");
    for (int i = n - 1; i >= 0; i--) {
        if (numerator[i] > 0) {
            int usedWeight = (numerator[i] == denominator[i]) ? weight[i] : numerator[i];
            printf("| x%d : %2d |\n", object[i], usedWeight);
        }
    }

    printf("------------\n");
    printf("Total Capacity = %d\n", capacity);
    printf("------------\n");
    printf("Total Profit = %.2f\n", totalProfit);

    printf("\nProfit breakdown sum: ");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" + ");
        printf("%.2f", valueAdded[i]);
    }
    printf(" = %.2f\n", totalProfit);

    return 0;
}
