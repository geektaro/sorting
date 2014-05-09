#include <stdio.h>

void insertsort(int a[], int length) {
    int i, j;
    for (i = 1; i < length; i++) {
        int key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--)
            a[j + 1] = a[j];
        a[j + 1] = key;
    }
}

void binsertsort(int a[], int length) {
    int i, j, low, high, mid, key;
    for (i = 1; i < length; i++) {
        key = a[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (key <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}

int main() {
    int a[] = {5, 2, 4, 6, 1, 3};
    binsertsort(a, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
