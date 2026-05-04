#include <stdio.h>
#include <string.h>
#define INF 99999

void printMatrix(int A[][10], int P[][10], int n) {
int i, j;
for(i = 0; i < n; i +) {
for(j = 0; j < n; j +) {
if(A[i][j] = INF)
printf("INF\t");
else {
if (P[i][j] = -1)
printf("%d(%d)\t", A[i][j], P[i][j] + 1);
else
printf("%d\t", A[i][j]);

}
}
printf("\n");
}
}
int main() {
int n, i, j, k;
char input[10];
int A[10][10];
int P[10][10];
printf("Enter number of vertices: ");
scanf("%d", &n);

for(i = 0; i < n; i +) {
for(j = 0; j < n; j +) {
P[i][j] = -1;
}
}
printf("Enter matrix (use INF for no edge):\n");
for(i = 0; i < n; i +) {
for(j = 0; j < n; j +) {
scanf("%s", input);
if(strcmp(input, "INF") = 0)
A[i][j] = INF;
else
sscanf(input, "%d", &A[i][j]);

}
}
printf("\nInitial Matrix:\n");
printMatrix(A, P, n);

for(k = 0; k < n; k +) {
for(i = 0; i < n; i +) {
for(j = 0; j < n; j +) {
if(A[i][k] = INF & A[k][j] = INF & (A[i][k] +

A[k][j] < A[i][j])) {

A[i][j] = A[i][k] + A[k][j];
P[i][j] = k;
}
}
}
printf("\nMatrix after considering vertex %d:\n", k+1);
printMatrix(A, P, n);
}
return 0;
}
