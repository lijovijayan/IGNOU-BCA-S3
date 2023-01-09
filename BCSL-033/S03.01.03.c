/*
Write a program in ‘C’ language for the creation of a list. Also, write a
procedure for deletion of an element from the list. Use pointers.
You have to write the above program separately for Singly linked list, Doubly
linked list and Circularly linked lists (both singly linked and doubly linked).
Make necessary assumptions.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node in the circularly linked list.
typedef struct node
{
    int data;
    struct node *next;
} Node;

// Define a pointer to the first node in the list.
Node *head = NULL;

// Function to create a new node with the given data and add it to the list.
void add_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node.
    new_node->data = data;                         // Set the data of the new node.

    // If the list is empty, set the new node as the first and only node in the list.
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        // Find the last node in the list.
        Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }

        // Add the new node to the end of the list.
        current->next = new_node;
        new_node->next = head;
    }
}

// Function to delete the node with the given data from the list.
void delete_node(int data)
{
    // If the list is empty, there is nothing to do.
    if (head == NULL)
    {
        return;
    }

    // If the node to be deleted is the first node in the list, we need to update the head pointer.
    if (head->data == data)
    {
        // If there is only one node in the list, we need to set the head pointer to NULL.
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            // Find the last node in the list.
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }

            // Set the second node in the list as the new head.
            current->next = head->next;
            free(head);
            head = current->next;
        }
    }
    else
    {
        // Find the node before the one to be deleted.
        Node *previous = head;
        while (previous->next != head && previous->next->data != data)
        {
            previous = previous->next;
        }

        // If the node to be deleted was not found in the list, there is nothing to do.
        if (previous->next == head)
        {
            return;
        }

        // Unlink the node to be deleted from the list.
        Node *node_to_delete = previous->next;
        previous->next = node_to_delete->next;
        free(node_to_delete);
    }
}

// Function to print the list.
void print_list()
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        printf("The list contains: ");
        Node *current = head;
        do
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }
}

int main()
{
    // Create a new list with some elements.
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);

    // Print the list.
    print_list();

    // Delete a node from the list.
    delete_node(3);

    // Print the updated list.
    print_list();

    return 0;
}

// Output:

// The list contains: 1 2 3 4 
// The list contains: 1 2 4