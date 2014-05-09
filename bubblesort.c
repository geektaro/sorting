#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int a[], int length) {
    int i, j;
    int flag = 1;
    for (i = length - 1; i > 0 && flag; i--) {
        flag = 0;
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
    }
}

int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27};
    bubblesort(a, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
