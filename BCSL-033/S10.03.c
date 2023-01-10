/*
Write a program in ‘C’ language for the creation of a AA-tree. Also, implement
insertion and deletion operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct AANode
{
    int level;
    int value;
    struct AANode *left;
    struct AANode *right;
};

struct AANode *skew(struct AANode *node)
{
    if (node && node->left && node->left->level == node->level)
    {
        struct AANode *temp = node;
        node = node->left;
        temp->left = node->right;
        node->right = temp;
    }
    return node;
}

struct AANode *split(struct AANode *node)
{
    if (node && node->right && node->right->right && node->level == node->right->right->level)
    {
        struct AANode *temp = node;
        node = node->right;
        temp->right = node->left;
        node->left = temp;
        node->level++;
    }
    return node;
}

struct AANode *insert(struct AANode *node, int value)
{
    if (!node)
    {
        node = (struct AANode *)malloc(sizeof(struct AANode));
        node->value = value;
        node->level = 1;
        node->left = NULL;
        node->right = NULL;
    }
    else if (value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = insert(node->right, value);
    }
    else
    {
        // value already exists in the tree
        return node;
    }
    node = skew(node);
    node = split(node);
    return node;
}

struct AANode *delete(struct AANode *node, int value)
{
    if (!node)
    {
        // value does not exist in the tree
        return node;
    }
    else if (value < node->value)
    {
        node->left = delete (node->left, value);
    }
    else if (value > node->value)
    {
        node->right = delete (node->right, value);
    }
    else
    {
        // value found in the tree
        if (!node->left && !node->right)
        {
            free(node);
            node = NULL;
        }
        else if (!node->left)
        {
            struct AANode *temp = node;
            node = node->right;
            free(temp);
        }
        else if (!node->right)
        {
            struct AANode *temp = node;
            node = node->left;
            free(temp);
        }
        else
        {
            struct AANode *temp = node->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            node->value = temp->value;
            node->left = delete (node->left, temp->value);
        }
    }
    if (node)
    {
        node = skew(node);
        if (node->right)
            node->right = skew(node->right);
        node = split(node);
        if (node->right)
            node->right = split(node->right);
    }
    return node;
}

void print_tree(struct AANode *node) {
    if (!node) return;
    print_tree(node->left);
    printf("%d ", node->value);
    print_tree(node->right);
}

int main()
{
    struct AANode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("\nTree after insertion: ");
    print_tree(root);

    root = delete (root, 30);
    printf("\nTree after deletion of 30: ");
    print_tree(root);

    return 0;
}

// Output: 
// Tree after insertion: 10 20 30 40 50 
// Tree after deletion of 30: 10 20 40 50