#include <stdio.h>

#define PARENT(i) i / 2
#define LEFT(i) 2 * i
#define RIGHT(i) (2 * i + 1)

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void max_heapify(int array[], const int size, const int pos) {
    int left, right, largest;
    left = LEFT(pos);
    right = RIGHT(pos);
    largest = (left <= size && array[left] > array[pos]) ? left : pos;
    if (right <= size && array[right] > array[largest])
        largest = right;
    if (largest != pos) {
        swap(&array[largest], &array[pos]);
        max_heapify(array, size, largest);
    }
}

void build_max_heap(int array[], const int size) {
    for (int i = size / 2; i > 0; i--)
        max_heapify(array, size, i);
}

void heapsort(int array[], int size) {
    build_max_heap(array, size);
    for (int i = size; i > 0; i--) {
        swap(&array[1], &array[i]);
        max_heapify(array, --size, 1); 
    }
}

int main() {
    int array[] = {0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    heapsort(array, 10);
    for (int i = 0; i < 11; i++)
        printf("%d ", array[i]);
    return 0;
}
