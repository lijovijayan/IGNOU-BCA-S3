/*
Write a program in ‘C’ language to implement 2-way Merge sort using pointers.
*/

#include <stdio.h>

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = *(arr + l + i);
    for (j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            *(arr + k) = L[i];
            i++;
        }
        else
        {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        *(arr + k) = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        *(arr + k) = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {4, 2, 9, 6, 23, 12, 34, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}

// Output:
// Sorted array: 0 1 2 4 6 9 12 23 34