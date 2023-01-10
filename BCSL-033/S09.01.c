/*
Write a program in ‘C’ language to implement linear search using pointers.
*/

#include <stdio.h>

int linear_search(int *arr, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (*(arr + i) == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4, 2, 9, 6, 23, 12, 34, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 34;
    int result = linear_search(arr, n, key);

    if (result == -1)
    {
        printf("Element not found in the array.");
    }
    else
    {
        printf("Element found at index %d", result);
    }

    return 0;
}

// Output:

// Element found at index 6