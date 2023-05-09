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

// на каждом проходе ищем максимальный или минимальный элемент запоминаем позицию и обменимаем с
// на первой..i позиции
void select_sort(int* arr, int n) // O(n^2), space complexity O(n)
{
    assert(arr != NULL && n > 0);

    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr + i, arr + min);
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
    select_sort(arr, length);
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
