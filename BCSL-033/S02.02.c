/*
Write a program in ‘C’ language to multiply two sparse matrices.
*/

// Explanation of sparse matrix: https://youtu.be/V3TAtTtC4Xs

#include <stdio.h>

// Define the maximum size of the matrices
#define MAX_SIZE 10

// Define a structure to represent a sparse matrix
struct SparseMatrix
{
    int m;
    int n;
    int num_nonzero_elements;
    int row[MAX_SIZE];
    int col[MAX_SIZE];
    int val[MAX_SIZE];
} A, B, C;

int main()
{
    // Prompt the user to enter the dimensions of the matrices
    printf("Enter the dimensions of matrix A (m x n): ");
    scanf("%d %d", &A.m, &A.n);
    printf("Enter the dimensions of matrix B (p x q): ");
    scanf("%d %d", &B.m, &B.n);

    // Check if the matrices can be multiplied
    if (A.n != B.m)
    {
        printf("Error: The matrices cannot be multiplied.\n");
        return 1;
    }

    // Prompt the user to enter the number of non-zero elements in the matrices
    printf("Enter the number of non-zero elements in matrix A: ");
    scanf("%d", &A.num_nonzero_elements);
    printf("Enter the number of non-zero elements in matrix B: ");
    scanf("%d", &B.num_nonzero_elements);

    // Prompt the user to enter the non-zero elements of matrix A
    printf("Enter the non-zero elements of matrix A:\n");
    for (int i = 0; i < A.num_nonzero_elements; i++)
    {
        printf("Row: ");
        scanf("%d", &A.row[i]);
        printf("Column: ");
        scanf("%d", &A.col[i]);
        printf("Value: ");
        scanf("%d", &A.val[i]);
        printf("\n");
    }

    // Prompt the user to enter the non-zero elements of matrix B
    printf("Enter the non-zero elements of matrix B:\n");
    for (int i = 0; i < B.num_nonzero_elements; i++)
    {
        printf("Row: ");
        scanf("%d", &B.row[i]);
        printf("Column: ");
        scanf("%d", &B.col[i]);
        printf("Value: ");
        scanf("%d", &B.val[i]);
        printf("\n");
    }

    // Initialize the number of non-zero elements in matrix C to 0
    C.num_nonzero_elements = 0;

    // Multiply the matrices
    for (int i = 0; i < A.num_nonzero_elements; i++)
    {
        for (int j = 0; j < B.num_nonzero_elements; j++)
        {
            // Check if the current elements of the matrices can be multiplied
            if (A.col[i] == B.row[j])
            {
                // Add the product of the current elements to matrix C
                C.row[C.num_nonzero_elements] = A.row[i];
                C.col[C.num_nonzero_elements] = B.col[j];
                C.val[C.num_nonzero_elements] = A.val[i] * B.val[j];
                C.num_nonzero_elements++;
            }
        }
    }

    // Print the result
    printf("The product of the matrices is:\n");
    for (int i = 0; i < C.num_nonzero_elements; i++)
    {
        printf("Row: %d\n", C.row[i]);
        printf("Column: %d\n", C.col[i]);
        printf("Value: %d\n", C.val[i]);
        printf("\n");
    }

    return 0;
}


// Output:

// Enter the dimensions of matrix A (m x n): 2 3
// Enter the dimensions of matrix B (p x q): 3 3
// Enter the number of non-zero elements in matrix A: 3
// Enter the number of non-zero elements in matrix B: 2
// Enter the non-zero elements of matrix A:
// Row: 0
// Column: Value: 0 
// 1

// Row: 1
// Column: 0
// Value: -1

// Row: 1
// Column: 2
// Value: 3

// Enter the non-zero elements of matrix B:
// Row: 0
// Column: 0
// Value: 7

// Row: 2
// Column: 2
// Value: 1

// The product of the matrices is:
// Row: 0
// Column: 0
// Value: 7

// Row: 1
// Column: 0
// Value: -7

// Row: 1
// Column: 2
// Value: 3