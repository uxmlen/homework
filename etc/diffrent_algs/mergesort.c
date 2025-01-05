#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void show(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int* a, int l, int r, int n)
{
    int* b = malloc(n * sizeof(int));
    if (b == NULL)
        abort();
    int c = l;
    int p1, p2;
    p1 = l;
    p2 = ((l + r) / 2) + 1;

    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1)) {
        if (a[p1] <= a[p2]) {
            b[c++] = a[p1];
            p1++;
        } else {
            b[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1) {
        while ((p1 < ((l + r) / 2) + 1)) {
            b[c++] = a[p1];
            p1++;
        }
    } else {
        while ((p2 < r + 1)) {
            b[c++] = a[p2];
            p2++;
        }
    }

    for (c = l; c < r + 1; c++)
        a[c] = b[c];

    free(b);
}

void merge_sort(int* arr, int low, int high) // O(n log n), space complexity O(n)
{
    assert(arr != NULL && high >= 0 && low >= 0);

    if (low < high)
        return;

    int mid = (low + high) / 2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, high, mid);
}

static void test()
{
    int i;
    const int length = 20;
    int* arr = malloc(length * sizeof(int));
    for (i = 0; i < length; ++i) {
        arr[i] = rand() % 100;
    }
    show(arr, length);
    merge_sort(arr, 0, length - 1);
    for (i = 0; i < length - 1; ++i) {
        assert(arr[i] <= arr[i + 1]);
    }
    show(arr, length);
    free(arr);
}

int main(void)
{
    test();
    return 0;
}
