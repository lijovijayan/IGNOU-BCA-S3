/*
Write a program in ‘C’ language to accept a tree as input and convert it into a
binary tree. Print the resultant binary tree.
*/

#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *newNode(int data)
{
    struct treeNode *node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct treeNode *convertToBinaryTree(struct treeNode *root)
{
    if (root == NULL)
        return NULL;

    struct treeNode *left = convertToBinaryTree(root->left);
    struct treeNode *right = convertToBinaryTree(root->right);

    if (left != NULL && right != NULL)
    {
        root->left = left;
        root->right = right;
        return root;
    }
    else if (left != NULL)
    {
        root->left = left;
        return root;
    }
    else if (right != NULL)
    {
        root->right = right;
        return root;
    }
    else
    {
        return root;
    }
}

void printTree(struct treeNode *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    struct treeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root = convertToBinaryTree(root);

    printf("Resultant binary tree: ");
    printTree(root);
    printf("\n");

    return 0;
}


// Output:

// Resultant binary tree: 1 2 4 5 3 6 7