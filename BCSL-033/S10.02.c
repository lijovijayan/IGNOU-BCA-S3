/*
Write a program in ‘C’ language for the creation of a Red Black tree. Also,
implement insertion and deletion operations.
*/

#include <stdio.h>
#include <stdlib.h>

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    enum Color color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

typedef struct Node Node;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->color = RED;
    node->left = node->right = NULL;
    node->parent = NULL;
    return node;
}

void rotateLeft(Node **root, Node *node)
{
    Node *right = node->right;
    node->right = right->left;
    if (right->left != NULL)
        right->left->parent = node;

    right->parent = node->parent;
    if (node->parent == NULL)
        *root = right;
    else if (node == node->parent->left)
        node->parent->left = right;
    else
        node->parent->right = right;

    right->left = node;
    node->parent = right;
}

void rotateRight(Node **root, Node *node)
{
    Node *left = node->left;
    node->left = left->right;
    if (left->right != NULL)
        left->right->parent = node;

    left->parent = node->parent;
    if (node->parent == NULL)
        *root = left;
    else if (node == node->parent->left)
        node->parent->left = left;
    else
        node->parent->right = left;

    left->right = node;
    node->parent = left;
}

void fixInsert(Node *root, Node *node)
{
    Node *uncle;
    while (node->parent != NULL && node->parent->color == RED)
    {
        if (node->parent == node->parent->parent->left)
        {
            uncle = node->parent->parent->right;

            if (uncle != NULL && uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    rotateLeft(&root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateRight(&root, node->parent->parent);
            }
        }
        else
        {
            uncle = node->parent->parent->left;

            if (uncle != NULL && uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rotateRight(&root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(&root, node->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

Node *insert(Node *root, int data)
{
    Node *node = newNode(data);
    if (root == NULL)
    {
        node->color = BLACK;
        return node;
    }

    Node *y = NULL;
    Node *x = root;
    while (x != NULL)
    {
        y = x;
        if (node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y == NULL)
        root = node;
    else if (node->data < y->data)
        y->left = node;
    else
        y->right = node;

    fixInsert(root, node);
    return root;
}
Node *getSuccessor(Node *node)
{
    Node *temp = node->right;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

Node *delete(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete (root->left, data);
    else if (data > root->data)
        root->right = delete (root->right, data);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = getSuccessor(root);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

void printInOrder(Node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);
    printf("%d(%s) ", root->data, root->color == BLACK ? "Black" : "Red");
    printInOrder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 50);

    printf("In-order Traversal: ");
    printInOrder(root);
    printf("\n");
    root = delete (root, 25);
    printf("After deletion of 25\n");
    printf("In-order Traversal: ");
    printInOrder(root);

    return 0;
}

// Output:

// In-order Traversal: 1(Red) 2(Black) 3(Red) 4(Black) 15(Black) 25(Black) 50(Red)
// After deletion of 25
// In-order Traversal: 1(Red) 2(Black) 3(Red) 4(Black) 15(Black) 50(Red)