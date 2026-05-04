#include <stdio.h>
int w[20], inc[20], n, sum, total;
int promising(int i, int wt, int rem) {
return (wt + rem = sum) & (wt = sum | wt + w[i+1] = sum);
}
void sumset(int i, int wt, int rem) {
if (promising(i, wt, rem)) {
if (wt = sum) {
printf("Subset = { ");
for (int j = 0; j < n; j +)
printf("%d ", inc[j]);
printf("}\n");
} else {
inc[i+1] = 1;
sumset(i+1, wt + w[i+1], rem - w[i+1]);
inc[i+1] = 0;
sumset(i+1, wt, rem - w[i+1]);
}
}
}
int main() {
printf("Enter no. of numbers: ");
scanf("%d", &n);
printf("Enter the elements: ");
for (int i = 0; i < n; i +) {
scanf("%d", &w[i]);
total += w[i];
inc[i] = 0;
}

printf("Enter maximum sum of subsets: ");
scanf("%d", &sum);
if (total < sum)
printf("No solution possible\n");
else
sumset(-1, 0, total);
return 0;
}
