#include <stdio.h>
#include <string.h>

#define INF 99999
#define MAX 10

void printMatrix(int A[][MAX], int P[][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] == INF) {
                printf("INF\t");
            } else {
                if (P[i][j] != -1)
                    printf("%d(%d)\t", A[i][j], P[i][j] + 1); // show intermediate vertex (1-based)
                else
                    printf("%d\t", A[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n, i, j, k;
    char input[32];
    int A[MAX][MAX];
    int P[MAX][MAX];

    printf("Enter number of vertices (<= %d): ", MAX);
    scanf("%d", &n);

    // Initialize P
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            P[i][j] = -1;
        }
    }

    printf("Enter matrix (use INF for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%s", input);
            if (strcmp(input, "INF") == 0)
                A[i][j] = INF;
            else
                sscanf(input, "%d", &A[i][j]);
        }
    }

    printf("\nInitial Matrix:\n");
    printMatrix(A, P, n);

    // Floyd-Warshall
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (A[i][k] != INF && A[k][j] != INF &&
                    A[i][k] + A[k][j] < A[i][j]) {

                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k; // store intermediate
                }
            }
        }
        printf("\nMatrix after considering vertex %d:\n", k + 1);
        printMatrix(A, P, n);
    }

    return 0;
}
