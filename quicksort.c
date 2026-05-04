#include <stdio.h>

int passes = 0;
int swaps = 0;

void swap(int arr[], int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
    swaps++;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int k = high;

    for (int i = high; i > low; i--) {
        passes++;
        if (arr[i] > pivot) {
            swap(arr, i, k);
            k--;
        }
    }

    swap(arr, k, low);
    return k;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(void) {
    int n;

    printf("Enter size of array: ");
    if (scanf("%d", &n) != 1) return 1;
    if (n <= 0) return 1;

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTotal passes: %d", passes);
    printf("\nTotal swaps: %d\n", swaps);

    return 0;
}
