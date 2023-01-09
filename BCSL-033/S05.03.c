/*
Write a program in ‘C’ language to reverse the elements of a queue.
*/

#include <stdio.h>

int f = -1, r = -1;
int q[50];

void enqueue(int data, int l) // Enqueue for inserting data
{
    if (r == l - 1)
    {
        printf("Queue is full");
    }
    else if ((f == -1) && (r == -1))
    {
        f = r = 0;
        q[r] = data;
    }
    else
    {
        r++;
        q[r] = data;
    }
}

void print() // Print function for printing the data
{
    int i;
    for (i = f; i <= r; i++)
    {
        printf("\t%d", q[i]);
    }
    printf("\n");
}

void reverse() // reverse function for reversing the data
{
    int i, j, t;
    for (i = f, j = r; i < j; i++, j--)
    {
        t = q[i];
        q[i] = q[j];
        q[j] = t;
    }
}

int main()
{
    int n, i = 0, t;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("\nEnter the data for Queue: ");
    while (i < n)
    {
        scanf("%d", &t);
        enqueue(t, n);
        i++;
    }
    printf("\nQueue which you have entered: ");
    print();
    reverse();
    printf("\nQueue after reversing: ");
    print();
    return 0;
}

// Output:

// Enter the size of Queue: 5
// Enter the data for Queue: 1 2 3 4 5
// Queue which you have entered:   1       2       3       4       5
// Queue after reversing:  5       4       3       2       1