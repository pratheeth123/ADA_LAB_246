#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high, temp;
    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void main() {
    int arr[SIZE];

    printf("Enter %d elements:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start, end;
    start = clock();
    quickSort(arr, 0, SIZE - 1);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("First %d elements of sorted array:\n",SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken for sorting: %f seconds\n", time_taken);
}
