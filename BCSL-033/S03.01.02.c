/*
Write a program in ‘C’ language for the creation of a list. Also, write a
procedure for deletion of an element from the list. Use pointers.
You have to write the above program separately for Singly linked list, Doubly
linked list and Circularly linked lists (both singly linked and doubly linked).
Make necessary assumptions.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node of a doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node *createNode(int data)
{
    // Allocate memory for the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Set the data of the new node
    newNode->data = data;

    // Set the next and previous pointers of the new node to NULL
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Function to delete a node from the doubly linked list
void deleteNode(struct Node **head, struct Node *nodeToDelete)
{
    // If the node to be deleted is the head node
    if (*head == nodeToDelete)
    {
        // Set the next node as the new head node
        *head = nodeToDelete->next;
    }

    // If the node to be deleted is not the last node
    if (nodeToDelete->next != NULL)
    {
        // Update the previous pointer of the next node
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    // If the node to be deleted is not the first node
    if (nodeToDelete->prev != NULL)
    {
        // Update the next pointer of the previous node
        nodeToDelete->prev->next = nodeToDelete->next;
    }

    // Free the memory occupied by the node to be deleted
    free(nodeToDelete);
}

// Function to print the doubly linked list
void printList(struct Node *head)
{
    // Start from the head node
    struct Node *current = head;

    printf("Doubly linked list: ");

    // Print the elements of the doubly linked list
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    // Create the doubly linked list
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    // Print the doubly linked list
    printList(head);

    // Delete the second node from the doubly linked list
    deleteNode(&head, head->next);

    // Print the doubly linked list after deleting the second node
    printList(head);

    return 0;
}


// Output:

// Doubly linked list: 1 2 3 4 
// Doubly linked list: 1 3 4