/*
Write a program in ‘C’ language to implement Heap sort using pointers.
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left<n &&*(arr + left)> * (arr + largest))
        largest = left;
    if (right<n &&*(arr + right)> * (arr + largest))
        largest = right;

    if (largest != i)
    {
        swap((arr + i), (arr + largest));
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--)
    {
        swap((arr + 0), (arr + i));
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {4, 2, 9, 6, 23, 12, 34, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]), i;
    heap_sort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}

// Output:
// Sorted array: 0 1 2 4 6 9 12 23 34