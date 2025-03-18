#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[SIZE];
    srand(time(0));


    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000 + 1;
    }

    clock_t start, end;
    start = clock();

    mergeSort(arr, 0, SIZE - 1);

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;


    printf("First 20 elements of sorted array: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken for sorting: %f seconds\n", time_taken);

    return 0;
}
