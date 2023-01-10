/*
Write a program in ‘C’ language to implement Quick sort using pointers.
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = *(arr + high);
    int i = low - 1, j;
    for (j = low; j <= high - 1; j++)
    {
        if (*(arr + j) <= pivot)
        {
            i++;
            swap((arr + i), (arr + j));
        }
    }
    swap((arr + i + 1), (arr + high));
    return (i + 1);
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {4, 2, 9, 6, 23, 12, 34, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]), i;

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }

    return 0;
}

// Output:
// Sorted array: 0 1 2 4 6 9 12 23 34