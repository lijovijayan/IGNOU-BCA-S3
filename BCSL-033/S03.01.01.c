/*
Write a program in ‘C’ language for the creation of a list. Also, write a
procedure for deletion of an element from the list. Use pointers.
You have to write the above program separately for Singly linked list, Doubly
linked list and Circularly linked lists (both singly linked and doubly linked).
Make necessary assumptions.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Define a pointer to the head of the linked list
struct Node *head = NULL;

// Function to create a new node and insert it into the linked list
void insert(int data)
{
    // Allocate memory for the new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the linked list is empty, set the new node as the head
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Otherwise, find the tail of the linked list and insert the new node there
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete an element from the linked list
void delete(int data)
{
    // If the linked list is empty, there is nothing to delete
    if (head == NULL)
    {
        return;
    }

    // If the element to be deleted is the head of the linked list,
    // set the head to the next element in the list
    if (head->data == data)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // Otherwise, search for the element to be deleted and remove it
    struct Node *current = head;
    while (current->next != NULL && current->next->data != data)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        // The element to be deleted was not found in the linked list
        return;
    }

    // The element to be deleted was found, so remove it
    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Function to print the elements of the linked list
void printList()
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    // Create a linked list with the elements 1, 2, 3, and 4
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    // Print the linked list
    printf("Linked list: ");
    printList();

    // Delete the element 3 from the linked list
    delete (3);

    // Print the linked list again
    printf("Linked list after deletion: ");
    printList();

    return 0;
}
