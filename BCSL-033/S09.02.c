/*
Write a program in ‘C’ language to implement binary search using pointers.
*/

#include <stdio.h>

int binary_search(int *arr, int low, int high, int key)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (*(arr + mid) == key)
        {
            return mid;
        }
        else if (*(arr + mid) > key)
        {
            return binary_search(arr, low, mid - 1, key);
        }
        else
        {
            return binary_search(arr, mid + 1, high, key);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 4, 6, 7, 8, 10, 13, 14, 18, 19, 21, 24, 37, 40, 45, 71};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 21;
    int result = binary_search(arr, 0, n - 1, key);

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
// Element found at index 11