/*
Write a program in ‘C’ language to implement a Dequeue using Arrays. All
operations associated with a Dequeue are to be implemented.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a Dequeue
struct Dequeue
{
    // array to store Dequeue elements
    int data[MAX_SIZE];

    // indices to keep track of front and rear of Dequeue
    int front, rear;
};

// Function to create a new Dequeue
struct Dequeue *createDequeue()
{
    // allocate memory for the Dequeue
    struct Dequeue *dequeue = (struct Dequeue *)malloc(sizeof(struct Dequeue));

    // initialize front and rear of Dequeue
    dequeue->front = dequeue->rear = -1;

    return dequeue;
}

// Function to check if the Dequeue is full
bool isFull(struct Dequeue *dequeue)
{
    // check if the rear of the Dequeue is at the last index
    return dequeue->rear == MAX_SIZE - 1;
}

// Function to check if the Dequeue is empty
bool isEmpty(struct Dequeue *dequeue)
{
    // check if the front of the Dequeue is at the first index
    return dequeue->front == -1;
}

// Function to insert an element at the front of the Dequeue
void insertFront(struct Dequeue *dequeue, int item)
{
    // check if the Dequeue is full
    if (isFull(dequeue))
        return;

    // if the Dequeue is empty, set the front and rear of the Dequeue to the same index
    if (isEmpty(dequeue))
        dequeue->front = dequeue->rear = 0;

    // otherwise, decrement the front of the Dequeue and add the element
    else
        dequeue->front = (dequeue->front - 1 + MAX_SIZE) % MAX_SIZE;

    dequeue->data[dequeue->front] = item;
}

// Function to insert an element at the rear of the Dequeue
void insertRear(struct Dequeue *dequeue, int item)
{
    // check if the Dequeue is full
    if (isFull(dequeue))
        return;

    // if the Dequeue is empty, set the front and rear of the Dequeue to the same index
    if (isEmpty(dequeue))
        dequeue->front = dequeue->rear = 0;

    // otherwise, increment the rear of the Dequeue and add the element
    else
        dequeue->rear = (dequeue->rear + 1) % MAX_SIZE;

    dequeue->data[dequeue->rear] = item;
}

// Function to delete an element from the front of the Dequeue
int deleteFront(struct Dequeue *dequeue)
{
    // check if the Dequeue is empty
    if (isEmpty(dequeue))
        return -1;

    // store the element at the front of the Dequeue
    int item = dequeue->data[dequeue->front];

    // if the Dequeue has only one element, set the front and rear of the Dequeue to -1
    if (dequeue->front == dequeue->rear)
        dequeue->front = dequeue->rear = -1;

    // otherwise, increment the front of the Dequeue and return the element
    else
        dequeue->front = (dequeue->front + 1) % MAX_SIZE;

    return item;
}

// Function to delete an element from the rear of the Dequeue
int deleteRear(struct Dequeue *dequeue)
{
    // check if the Dequeue is empty
    if (isEmpty(dequeue))
        return -1;

    // store the element at the rear of the Dequeue
    int item = dequeue->data[dequeue->rear];

    // if the Dequeue has only one element, set the front and rear of the Dequeue to -1
    if (dequeue->front == dequeue->rear)
        dequeue->front = dequeue->rear = -1;

    // otherwise, decrement the rear of the Dequeue and return the element
    else
        dequeue->rear = (dequeue->rear - 1 + MAX_SIZE) % MAX_SIZE;

    return item;
}

// Function to get the front element of the Dequeue
int getFront(struct Dequeue *dequeue)
{
    // check if the Dequeue is empty
    if (isEmpty(dequeue))
        return -1;

    // return the front element of the Dequeue
    return dequeue->data[dequeue->front];
}

// Function to get the rear element of the Dequeue
int getRear(struct Dequeue *dequeue)
{
    // check if the Dequeue is empty
    if (isEmpty(dequeue))
        return -1;

    // return the rear element of the Dequeue
    return dequeue->data[dequeue->rear];
}

// Function to test the Dequeue implementation
int main()
{
    // create a new Dequeue
    struct Dequeue *dequeue = createDequeue();

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

// Output: 
// Dequeue: 3 2 1 4 5 6