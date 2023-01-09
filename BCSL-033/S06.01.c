/*
Write a program in ‘C’ language for the creation of a binary tree. Also, provide
for insertion and deletion operations.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new binary tree node
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node in the binary tree
void insertNode(struct Node *root, int data)
{
    if (data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = createNode(data);
        }
        else
        {
            insertNode(root->left, data);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = createNode(data);
        }
        else
        {
            insertNode(root->right, data);
        }
    }
}

// Function to find the minimum value node in the binary tree
struct Node *findMinNode(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary tree
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct Node *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void printInOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main()
{
    // Create the root node of the binary tree
    struct Node *root = createNode(5);

    // Insert some nodes in the binary tree
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 6);
    insertNode(root, 8);

    printf("Tree before deletion: ");
    printInOrder(root);

    // Delete a node from the binary tree
    root = deleteNode(root, 7);

    printf("\nTree after deletion: ");
    printInOrder(root);

    return 0;
}

// Output:

// Tree before deletion: 2 3 4 5 6 7 8 
// Tree after deletion: 2 3 4 5 6 8