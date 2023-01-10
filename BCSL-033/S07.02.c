/*
Write a program in ‘C’ language to insert 15, 25, 2, 4, 3, 1, 50 into an initially
empty AVL tree. Make assumptions, if necessary.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node in the AVL tree with left and right child pointers
// and the data value
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to insert a new node into the AVL tree
Node *insert(Node *root, int data)
{
    // If the tree is empty, return a new node
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    // If the data value is less than the root data value, insert it into the left subtree
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    // If the data value is greater than or equal to the root data value, insert it into the right subtree
    else
    {
        root->right = insert(root->right, data);
    }

    // Return the root of the updated tree
    return root;
}

void printTreeFormatted(Node *root, int space)
{
    // Base case: if the tree is empty, do nothing
    if (root == NULL)
    {
        return;
    }

    // Increase the indentation for the right subtree
    space += 10;

    // Print the right subtree
    printTreeFormatted(root->right, space);

    // Print the root data value with the appropriate indentation
    printf("\n");
    for (int i = 10; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Print the left subtree with the appropriate indentation
    printTreeFormatted(root->left, space);
}

void print_tree(struct Node *root, int level)
{
    if (root == NULL)
        return;
    print_tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("|   ");
    printf("%d\n", root->data);
    print_tree(root->left, level + 1);
}

int main()
{
    // Create an empty AVL tree
    Node *root = NULL;

    // Insert the values into the tree
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 50);

    // The AVL tree now contains the values 15, 25, 2, 4, 3, 1, 50

    // printTreeFormatted(root, 0);
    print_tree(root, 0);
    return 0;
}

/* 
Output:

|   |   50
|   25
15
|   |   4
|   |   |   3
|   2
|   |   1

*/