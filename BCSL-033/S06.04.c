/*
Write a program in ‘C’ language to accept a binary tree as input and check if the
input binary tree is a full binary tree or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to check if the binary tree is a full binary tree
bool isFullBinaryTree(struct Node *root)
{
    // An empty tree is a full binary tree
    if (root == NULL)
        return true;

    // If the tree has only one node, it is a full binary tree
    if (root->left == NULL && root->right == NULL)
        return true;

    // If the tree has more than one node, it is a full binary tree
    // only if both its left and right subtrees are also full binary trees
    if (root->left != NULL && root->right != NULL)
    {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    // If none of the above conditions are met, the tree is not a full binary tree
    return false;
}

int main()
{
    // Create the root node of the binary tree
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = 5;
    root->left = NULL;
    root->right = NULL;

    // Insert some nodes in the binary tree
    root->left = (struct Node *)malloc(sizeof(struct Node));
    root->left->data = 3;
    root->left->left = NULL;
    root->left->right = NULL;

    root->right = (struct Node *)malloc(sizeof(struct Node));
    root->right->data = 7;
    root->right->left = NULL;
    root->right->right = NULL;

    // Check if the binary tree is a full binary tree
    if (isFullBinaryTree(root))
    {
        printf("The binary tree is a full binary tree.\n");
    }
    else
    {
        printf("The binary tree is not a full binary tree.\n");
    }

    return 0;
}

// Output:

// The binary tree is a full binary tree.