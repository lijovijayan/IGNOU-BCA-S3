/*
Write a program in ‘C’ language to accept a singly linked list of integers as
input. Now, sort the elements of the list in ascending order. Then, accept an
integer as input. Insert this integer into the singly linked list at the appropriate
position.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node
{
    int data;          // Data field to store the integer
    struct Node *next; // Pointer to the next node in the list
};

// Function prototypes
void insert(struct Node **head, int data);
void sort(struct Node *head);
void printList(struct Node *head);

int main()
{
    // Create an empty singly linked list
    struct Node *head = NULL;

    // Insert some integers into the list
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 8);

    // Print the unsorted list
    printf("Unsorted list: ");
    printList(head);

    // Sort the list in ascending order
    sort(head);

    // Print the sorted list
    printf("Sorted list: ");
    printList(head);

    // Insert a new integer into the list
    int newInt;
    printf("Enter an integer to insert: ");
    scanf("%d", &newInt);
    insert(&head, newInt);

    // Print the updated list
    printf("Updated list: ");
    printList(head);

    return 0;
}

// Function to insert a new node at the end of the list
void insert(struct Node **head, int data)
{
    // Create a new node with the given data
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, set the new node as the head
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Otherwise, traverse the list until we find the last node
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    // Insert the new node at the end of the list
    current->next = newNode;
}

// Function to sort the list in ascending order
void sort(struct Node *head)
{
    // Check if the list is empty
    if (head == NULL)
    {
        return;
    }

    // Traverse the list and compare each node with the rest of the nodes
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *nextNode = current->next;
        while (nextNode != NULL)
        {
            // If the current node's data is greater than the next node's data,
            // swap the two nodes
            if (current->data > nextNode->data)
            {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

// Function to print the elements of the list
void printList(struct Node *head)
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // Otherwise, traverse the list and print each element
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Output

// Unsorted list: 5 10 3 2 8 
// Sorted list: 2 3 5 8 10