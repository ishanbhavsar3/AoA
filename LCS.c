#include <stdio.h>
#include <string.h>

#define MAX 100

int c[MAX + 1][MAX + 1];
char b[MAX + 1][MAX + 1];

void printTables(char X[], char Y[], int m, int n) {
    printf("\nValue + Direction Table:\n\n");

    printf("     ");
    for (int j = 1; j <= n; j++) {
        printf("%6c", Y[j - 1]);
    }
    printf("\n");

    for (int i = 0; i <= m; i++) {
        if (i == 0) printf("   ");
        else        printf("%3c", X[i - 1]);

        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                printf("%6d", c[i][j]);
            } else {
                if (b[i][j] == 'D')
                    printf("%4d%c", c[i][j], '\\');   // diagonal
                else if (b[i][j] == 'U')
                    printf("%4d%c", c[i][j], '^');    // up
                else
                    printf("%4d%c", c[i][j], '<');    // left
            }
        }
        printf("\n");
    }
}

void printLCS(char X[], int i, int j) {
    if (i == 0 || j == 0) return;

    if (b[i][j] == 'D') {
        printLCS(X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    } else if (b[i][j] == 'U') {
        printLCS(X, i - 1, j);
    } else {
        printLCS(X, i, j - 1);
    }
}

int main() {
    char X[MAX + 1], Y[MAX + 1];
    int m, n;

    printf("Enter first sequence: ");
    scanf("%100s", X);

    printf("Enter second sequence: ");
    scanf("%100s", Y);

    m = (int)strlen(X);
    n = (int)strlen(Y);

    for (int i = 0; i <= m; i++) c[i][0] = 0;
    for (int j = 0; j <= n; j++) c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';
            }
        }
    }

    printTables(X, Y, m, n);

    printf("\nLength of LCS: %d\n", c[m][n]);
    printf("Longest Common Subsequence: ");
    printLCS(X, m, n);
    printf("\n");

    return 0;
}
