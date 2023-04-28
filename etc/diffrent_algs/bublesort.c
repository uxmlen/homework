#include <stdbool.h>
#include <stdio.h>

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
/*
void bubble_sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + i);
            }
        }
    }
}*/

void bubble_sort(int* arr, int len) // O(n^2)
{
    bool br = true;
    for (int i = len; i > 1; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + i);
                br = false; // если хотя бы раз была перестановка
            }
        }
        if (br)
            break; // завершаем сортировка т.к. не выполнилось не одной
                   // перестановки и это значит, что массив уже отсортирован
    }
}

int main(void)
{
    static int arr[] = { 37, 48, 24, 13, 20, 4, 5, 6, 9 };
    int n = sizeof(arr) / sizeof(*arr);
    show(arr, n);
    bubble_sort(arr, n);
    show(arr, n);
}
