/*
Write a program in ‘C’ language to implement a Dequeue using pointers. All
operations associated with a Dequeue are to be implemented.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a Dequeue node
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

// Structure to represent a Dequeue
struct Dequeue
{
    struct Node* front;
    struct Node* rear;
};

// Function to create a new Dequeue node
struct Node* createNode(int data)
{
    // allocate memory for the node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    // initialize the node
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

// Function to create a new Dequeue
struct Dequeue* createDequeue()
{
    // allocate memory for the Dequeue
    struct Dequeue* dequeue = (struct Dequeue*)malloc(sizeof(struct Dequeue));

    // initialize the front and rear of the Dequeue
    dequeue->front = NULL;
    dequeue->rear = NULL;

    return dequeue;
}

// Function to check if the Dequeue is empty
bool isEmpty(struct Dequeue* dequeue)
{
    // check if the front of the Dequeue is NULL
    return dequeue->front == NULL;
}

// Function to insert an element at the front of the Dequeue
void insertFront(struct Dequeue* dequeue, int data)
{
    // create a new Dequeue node
    struct Node* node = createNode(data);

    // if the Dequeue is empty, set the front and rear of the Dequeue to the same node
    if (isEmpty(dequeue))
        dequeue->front = dequeue->rear = node;

    // otherwise, set the next pointer of the new node to the front of the Dequeue,
    // set the prev pointer of the current front node to the new node,
    // and set the front of the Dequeue to the new node
    else
    {
        node->next = dequeue->front;
        dequeue->front->prev = node;
        dequeue->front = node;
    }
}

// Function to insert an element at the rear of the Dequeue
void insertRear(struct Dequeue* dequeue, int data)
{
    // create a new Dequeue node
    struct Node* node = createNode(data);

    // if the Dequeue is empty, set the front and rear of the Dequeue to the same node
    if (isEmpty(dequeue))
        dequeue->front = dequeue->rear = node;

    // otherwise, set the prev pointer of the new node to the rear of the Dequeue,
    // set the next pointer of the current rear node to the new node,
    // and set the rear of the Dequeue to the new node
    else
    {
        node->prev = dequeue->rear;
        dequeue->rear->next = node;
        dequeue->rear = node;
    }
}

// Function to delete an element from the front of the Dequeue
int deleteFront(struct Dequeue* dequeue)
{
    // check if the Dequeue is empty
    if (isEmpty(dequeue))
        return -1;

    // store the front node of the Dequeue
    struct Node* front = dequeue->front;

    // if the Dequeue has only one element, set the front and rear of the Dequeue to NULL
    if (dequeue->front == dequeue->rear)
        dequeue->front = dequeue->rear = NULL;

    // otherwise, set the front of the Dequeue to the next node and free the current front node
    else
    {
        dequeue->front = dequeue->front->next;
        dequeue->front->prev = NULL;
        free(front);
    }

    // return the data of the current front node
    return front->data;
}

// Function to delete an element from the rear of the Dequeue
int deleteRear(struct Dequeue* dequeue)
{
    // check if the Dequeue is empty
    if (isEmpty(dequeue))
        return -1;

    // store the rear node of the Dequeue
    struct Node* rear = dequeue->rear;

    // if the Dequeue has only one element, set the front and rear of the Dequeue to NULL
    if (dequeue->front == dequeue->rear)
        dequeue->front = dequeue->rear = NULL;

    // otherwise, set the rear of the Dequeue to the previous node and free the current rear node
    else
    {
        dequeue->rear = dequeue->rear->prev;
        dequeue->rear->next = NULL;
        free(rear);
    }

    // return the data of the current rear node
    return rear->data;
}

// Function to get the front element of the Dequeue
int getFront(struct Dequeue* dequeue)
{
    // check if the Dequeue is empty
    if (isEmpty(dequeue))
        return -1;

    // return the data of the front node of the Dequeue
    return dequeue->front->data;
}

// Function to get the rear element of the Dequeue
int getRear(struct Dequeue* dequeue)
{
    // check if the Dequeue is empty
    if (isEmpty(dequeue))
        return -1;

    // return the data of the rear node of the Dequeue
    return dequeue->rear->data;
}

// Function to test the Dequeue implementation
int main()
{
    // create a new Dequeue
    struct Dequeue* dequeue = createDequeue();

    // insert elements at the front of the Dequeue
    insertFront(dequeue, 1);
    insertFront(dequeue, 2);
    insertFront(dequeue, 3);

    // insert elements at the rear of the Dequeue
    insertRear(dequeue, 4);
    insertRear(dequeue, 5);
    insertRear(dequeue, 6);

    // print the Dequeue
    printf("Dequeue: ");

    while (!isEmpty(dequeue))
        printf("%d ", deleteFront(dequeue));

    return 0;
}
