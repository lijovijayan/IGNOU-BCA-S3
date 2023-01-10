/*
Write a program in ‘C’ language to implement Bubble sort using pointers.
*/

#include <stdio.h>

void bubble_sort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {4, 2, 9, 6, 23, 12, 34, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]), i;
    bubble_sort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}

// Output:
// Sorted array: 0 1 2 4 6 9 12 23 34
