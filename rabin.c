#include <stdio.h>
#include <string.h>

void search(const char txt[], const char pat[], int q, int d) {
    int M = (int)strlen(pat);
    int N = (int)strlen(txt);

    if (M == 0) {
        printf("Empty pattern.\n");
        return;
    }
    if (M > N) {
        printf("Pattern longer than text. No matches.\n");
        return;
    }

    int h = 1;  // d^(M-1) % q
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for current text window

    for (int i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < M; i++) {
        p = (d * p + (unsigned char)pat[i]) % q;
        t = (d * t + (unsigned char)txt[i]) % q;
    }

    printf("\n- Results -\n");
    printf("Pattern: %s\nText: %s\nModulus: %d\n\n", pat, txt, q);

    for (int i = 0; i <= N - M; i++) {
        printf("Shift %d:\n", i + 1);
        printf("Current substring: ");
        for (int k = 0; k < M; k++) {
            putchar(txt[i + k]);
        }
        printf("\n");

        if (p == t) {
            int j;
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            if (j == M) {
                printf("Actual match found at index %d (p=%d, t=%d)\n", i, p, t);
            } else {
                printf("Spurious hit at index %d (p=%d, t=%d)\n", i, p, t);
            }
        } else {
            printf("Hash not matched (p=%d, t=%d)\n", p, t);
        }

        if (i < N - M) {
            t = (d * (t - (unsigned char)txt[i] * h) + (unsigned char)txt[i + M]) % q;
            if (t < 0) t += q;
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

    if (scanf("%d", &choice) != 1) return 1;
    getchar(); // consume newline after number input

    printf("Enter Text: ");
    if (!fgets(txt, sizeof(txt), stdin)) return 1;
    txt[strcspn(txt, "\n")] = '\0';

    printf("Enter Pattern: ");
    if (!fgets(pat, sizeof(pat), stdin)) return 1;
    pat[strcspn(pat, "\n")] = '\0';

    if (choice == 1) {
        search(txt, pat, 26, 256);
    } else if (choice == 2) {
        search(txt, pat, 52, 256);
    } else if (choice == 3) {
        search(txt, pat, 62, 256);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
