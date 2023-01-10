/*
Write a program in ‘C’ language to accept two trees as input and check if both
of them are the same. Give the appropriate message.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    return p->data == q->data && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    // Set up the two trees

    struct TreeNode *tree1 = malloc(sizeof(struct TreeNode));
    tree1->data = 1;
    tree1->left = malloc(sizeof(struct TreeNode));
    tree1->left->data = 2;
    tree1->right = malloc(sizeof(struct TreeNode));
    tree1->right->data = 3;
    tree1->left->left = NULL;
    tree1->left->right = NULL;
    tree1->right->left = NULL;
    tree1->right->right = NULL;

    struct TreeNode *tree2 = malloc(sizeof(struct TreeNode));
    tree2->data = 1;
    tree2->left = malloc(sizeof(struct TreeNode));
    tree2->left->data = 2;
    tree2->right = malloc(sizeof(struct TreeNode));
    tree2->right->data = 3;
    tree2->left->left = NULL;
    tree2->left->right = NULL;
    tree2->right->left = NULL;
    tree2->right->right = NULL;

    // Check if they are the same
    if (isSameTree(tree1, tree2))
    {
        printf("The trees are the same.\n");
    }
    else
    {
        printf("The trees are not the same.\n");
    }

    return 0;
}

// Output:

// The trees are the same.