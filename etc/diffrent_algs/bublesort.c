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

void bubble_sort_3(int* arr, int len)
{
    assert(arr != NULL && len > 0);

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + i);
            }
        }
    }
}

void bubble_sort_2(int* arr, int len) // O(n^2)
{
    assert(arr != NULL && len > 0);
    bool swapped = true;

    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + 1);
                swapped = false; // если хотя бы раз была перестановка
            }
        }
        if (swapped)
            return; // завершаем сортировка т.к. не выполнилось не одной
                    // перестановки и это значит, что массив уже отсортирован
    }
}

void bubble_sort(int* arr, int len) // O(n^2)
{
    assert(arr != NULL && len > 0);
    bool swapped = true;

    for (int i = len; swapped; i--) {
        swapped = false;
        for (int j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + 1);
                swapped = true; // если хотя бы раз была перестановка
            }
        }
    }
}

void sift_sort(int* arr, int len)
{
    assert(arr != NULL && len > 0);

    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr + j, arr + j - 1);
        }
    }
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
    bubble_sort_2(arr, length);
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
