/*
Write a program in ‘C’ language to insert 15, 25, 2, 4, 3, 1, 50 into an initially
empty Splay tree.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct node *insert(struct node *root, int data)
{
    if (!root)
        return newNode(data);

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void printInOrder(struct node *root)
{
    if (!root)
        return;

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main()
{
    struct node *root = NULL;
    printf("Inserting 15, 25, 2, 4, 3, 1, and 50\n");
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 50);

    printf("Inserted Elements in order: ");
    printInOrder(root);
    return 0;
}

// Output:
// Inserting 15, 25, 2, 4, 3, 1, and 50
// Inserted Elements in order: 1 2 3 4 15 25 50