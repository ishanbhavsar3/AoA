#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int x[20];
int count = 0;
int place(int k, int i) {
for (int j = 1; j < k; j +) {
if ((x[j] = i) | (abs(x[j] - i) = abs(j - k))) {
return 0;
}
}
return 1;
}
void nqueens(int k, int n) {
for (int i = 1; i = n; i +) {
if (place(k, i)) {
x[k] = i;
if (k = n) {
printf("\nSolution %d: ", +count);
for (int m = 1; m = n; m +) {
printf("%d ", x[m]);
}
} else {
nqueens(k + 1, n);
}
}
}
}
int main() {
int n = 8;
nqueens(1, n);
return 0;
}
