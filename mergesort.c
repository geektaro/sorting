#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

void merge(int array[], int start, int mid, int end) {
    int i, j, k;
    int *temp = (int *) malloc(sizeof(int) * (end - start + 1));
    for (i = start, j = mid + 1, k = 0; i <= mid && j <= end; k++) {
        if (array[i] <= array[j])
            temp[k] = array[i++];
        else
            temp[k] = array[j++];
    }
    for (; i <= mid; i++, k++)
        temp[k] = array[i];
    for (; j <= end; j++, k++)
        temp[k] = array[j];
    for (i = 0; i < k; i++)
        array[start + i] = temp[i];
    free(temp);
}

void merge_sort(int array[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

int main() {
    int array[SIZE] = {49, 38, 65, 97, 76, 13, 27};
    merge_sort(array, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    return 0;
}
