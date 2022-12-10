/*
Write a program in ‘C’ language for the creation of a binary tree. Also, provide
for insertion and deletion operations.
*/

#include <stdio.h>
#include <stdlib.h>

// binary tree node
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

// create a new node
Node *create_node(int data)
{
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// insert a new node into the binary tree
void insert(Node **root, int data)
{
    // create a new node
    Node *n = create_node(data);

    // if the tree is empty, set the new node as the root
    if (*root == NULL)
    {
        *root = n;
        return;
    }

    // find the correct position for the new node
    Node *current = *root;
    while (1)
    {
        if (data < current->data)
        {
            // if the new data is less than the current node's data,
            // it should be inserted in the left subtree
            if (current->left == NULL)
            {
                current->left = n;
                return;
            }
            else
            {
                current = current->left;
            }
        }
        else
        {
            // if the new data is greater than or equal to the current node's data,
            // it should be inserted in the right subtree
            if (current->right == NULL)
            {
                current->right = n;
                return;
            }
            else
            {
                current = current->right;
            }
        }
    }
}

// delete a node from the binary tree
void delete(Node **root, int data)
{
    // if the tree is empty, there is nothing to do
    if (*root == NULL)
    {
        return;
    }

    // find the node to be deleted
    Node *current = *root;
    Node *parent = NULL;
    while (current != NULL)
    {
        if (data < current->data)
        {
            // the node to be deleted is in the left subtree
            parent = current;
            current = current->left;
        }
        else if (data > current->data)
        {
            // the node to be deleted is in the right subtree
            parent = current;
            current = current->right;
        }
        else
        {
            // we have found the node to be deleted
            break;
        }
    }

    // if the node was not found, there is nothing to do
    if (current == NULL)
    {
        return;
    }

    // if the node to be deleted has two children,
    // we need to find its in-order successor
    if (current->left != NULL && current->right != NULL)
    {
        // find the in-order successor
        Node *successor = current->right;
        while (successor->left != NULL)
        {
            successor = successor->left;
        }

        // copy the data from the successor to the current node
        current->data = successor->data;

        // delete the successor
        if (parent->left == successor)
        {
            parent->left = successor->right;
        }
        else
        {
            parent->right = successor->right;
        }
        free(successor);
    }
}

void print_in_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // print the left subtree
    print_in_order(root->left);

    // print the current node
    printf("%d ", root->data);

    // print the right subtree
    print_in_order(root->right);
}

// main function
int main()
{
    // create an empty binary tree
    Node *root = NULL;

    // insert some nodes into the tree
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);

    // delete a node from the tree
    delete (&root, 7);

    // print the elements of the tree in in-order
    print_in_order(root);

    return 0;
}
