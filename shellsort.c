#include <stdio.h>

void shellsort(int a[], int length) {
    int i, j, step, key;
    for (step = length / 2; step > 0; step /= 2) {
        for (i = step; i < length; i++) {
            key = a[i];
            for (j = i - step; j >= 0 && a[j] > key; j -= step)
                a[j + step] = a[j];
            a[j + step] = key;
        }
    }
}

int main() {
    int a[] = {5, 2, 4, 6, 1, 3};
    shellsort(a, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
