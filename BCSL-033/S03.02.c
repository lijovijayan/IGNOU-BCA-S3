/*
Write a program in ‘C’ language that accepts two singly linked lists A and B as
input. Now, print a singly linked list that consists of only those elements, which
are common to both A and B.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list.
typedef struct node
{
    int data;
    struct node *next;
} Node;

// Define a pointer to the first node in the list.
Node *headA = NULL;
Node *headB = NULL;

// Function to create a new node with the given data and add it to the list.
void add_node(Node **head, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node.
    new_node->data = data;                         // Set the data of the new node.
    new_node->next = NULL;                         // Set the next pointer of the new node to NULL.

    // If the list is empty, set the new node as the first and only node in the list.
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        // Find the last node in the list.
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Add the new node to the end of the list.
        current->next = new_node;
    }
}

// Function to search for the given data in the given list.
int search(Node *head, int data)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to print the list.
void print_list(Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        printf("The list contains: ");
        Node *current = head;
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    // Create the first list.
    add_node(&headA, 1);
    add_node(&headA, 2);
    add_node(&headA, 3);
    add_node(&headA, 4);

    // Create the second list.
    add_node(&headB, 3);
    add_node(&headB, 4);
    add_node(&headB, 5);
    add_node(&headB, 6);

    // Print the first list.
    printf("List A: ");
    print_list(headA);

    // Print the second list.
    printf("List B: ");
    print_list(headB);

    // Create a new list to hold the common elements.
    Node *common = NULL;

    // Loop through the first list and add common elements to the new list.
    Node *current = headA;
    while (current != NULL)
    {
        if (search(headB, current->data))
        {
            add_node(&common, current->data);
        }
        current = current->next;
    }

    // Print the common elements list.
    printf("The common elements are: ");
    print_list(common);

    return 0;
}

// Output:

// List A: The list contains: 1 2 3 4 
// List B: The list contains: 3 4 5 6 
// The common elements are: The list contains: 3 4