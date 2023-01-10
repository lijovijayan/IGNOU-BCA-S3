/*
Write a program in ‘C’ language for pre-order, post-order and in-order
tranversals of a Binary tree. Don’t use Recursion.
*/

#include <stdio.h>
#include <stdlib.h>

// define a tree node
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;

// create a new tree node
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// perform pre-order traversal of the tree
void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data); // visit the root
    preOrder(root->left);      // traverse left subtree
    preOrder(root->right);     // traverse right subtree
}

// perform in-order traversal of the tree
void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);       // traverse left subtree
    printf("%d ", root->data); // visit the root
    inOrder(root->right);      // traverse right subtree
}

// perform post-order traversal of the tree
void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);     // traverse left subtree
    postOrder(root->right);    // traverse right subtree
    printf("%d ", root->data); // visit the root
}

int main()
{
    // create a binary tree
    printf("Inserting numbers 1 to 7\n");
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // perform pre-order traversal
    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    // perform in-order traversal
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    // perform post-order traversal
    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}

// Output:

// Inserting numbers 1 to 7
// Pre-order traversal: 1 2 4 5 3 6 7 
// In-order traversal: 4 2 5 1 6 3 7 
// Post-order traversal: 4 5 2 6 7 3 1