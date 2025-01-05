#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void show(const int* arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int quick_sort_splitting(int* arr, int n)
{
    int left = -1, right = n;
    double v = 0.5 * (arr[0] + arr[n - 1]);
    while (true) {
    }
}

void quick_sort(int* arr, int n)
{
    assert(arr != NULL);
    if (n < 2)
        return;
    int k = quick_sort_splitting(arr, n);
    quick_sort(arr, k);
    quick_sort(arr + k, n - k);
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
    quick_sort(arr, length);
    for (i = 0; i < length - 1; ++i) {
        assert(arr[i] <= arr[i + 1]);
    }
    show(arr, length);
    free(arr);
}

int main(void)
{
    srand(time(NULL));
    test();
    return 0;
}
