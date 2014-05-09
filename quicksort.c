#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[], int low, int high) {
    int i, j;
    int pivot = array[high];
    for (i = 0; i <= high && array[i] <= pivot; i++);
    for (j = i; j < high; j++) {
        if (array[j] <= pivot) {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[j]);
    return i;
}

int alternate_partition(int array[], int low, int high) {
    int i, j;
    int pivot = array[high];
    for (i = low - 1, j = low; j <= high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    return i;
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int mid = alternate_partition(array, low, high);
        quicksort(array, low, mid - 1);
        quicksort(array, mid + 1, high);
    }
}

int main() {
    int array[] = {26, 38, 65, 97, 76, 13, 27};
    quicksort(array, 0, 6);
    for (int i = 0; i < 7; i++)
        printf("%d ", array[i]);
    return 0;
}
