#include <stdio.h>
#include <string.h>
void search(char txt[], char pat[], int q, int d) {
int M = strlen(pat);
int N = strlen(txt);
int h = 1;
int p = 0;
int t = 0;
for (int i = 0; i < M - 1; i +) {
h = (h * d) % q;
}
for (int i = 0; i < M; i +) {
p = (p * d + pat[i]) % q;
t = (t * d + txt[i]) % q;
}
printf("\n - Results -\n");
printf("Pattern: %s\nText: %s\nModulus: %d\n", pat, txt, q);
for (int i = 0; i = N - M; i +) {
printf("Shift %d:\n", i + 1);
printf("Current substring: ");
for (int k = 0; k < M; k +) {
printf("%c", txt[i + k]);
}
printf("\n");
if (p = t) {
int j;
for (j = 0; j < M; j +) {
if (txt[i + j] = pat[j]) {
break;

}
}
if (j = M) {
printf("Actual match found at index %d (p=%d,

t=%d)\n", i, p, t);
} else {
printf("Spurious hit at index %d (p=%d, t=%d)\n",

i, p, t);

}
} else {
printf("Hash not matched (p=%d, t=%d)\n", p, t);
}
if (i < N - M) {
t = (d * (t - txt[i] * h) + txt[i + M]) % q;
if (t < 0) {
t = (t + q);
}
}
printf("\n");
}
}
int main() {
char txt[100], pat[100];
int choice;
printf("Select Test Case:\n");
printf("1. Lowercase (Mod 26)\n");
printf("2. Lowercase + Uppercase (Mod 52)\n");
printf("3. Lowercase + Uppercase + Numbers (Mod 62)\n");
printf("Choice: ");
scanf("%d", &choice);
getchar();
printf("Enter Text: ");
fgets(txt, sizeof(txt), stdin);

txt[strcspn(txt, "\n")] = 0;
printf("Enter Pattern: ");
fgets(pat, sizeof(pat), stdin);
pat[strcspn(pat, "\n")] = 0;
if (choice = 1) {
search(txt, pat, 26, 256);
} else if (choice = 2) {
search(txt, pat, 52, 256);
} else if (choice = 3) {
search(txt, pat, 62, 256);
} else {
printf("Invalid choice\n");
}
return 0;
}
