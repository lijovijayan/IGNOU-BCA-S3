/*
Write a program in ‘C’ language to reverse the elements of a queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a queue
struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
};

// Function to create a new queue
struct Queue *createQueue()
{
    // allocate memory for the queue
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    // initialize the front and rear of the queue
    queue->front = 0;
    queue->rear = 0;

    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue)
{
    // check if the front and rear of the queue are at the same index
    return queue->front == queue->rear;
}

// Function to check if the queue is full
bool isFull(struct Queue *queue)
{
    // check if the rear of the queue has reached the end of the array and the front of the queue is at index 0
    return queue->rear == MAX_SIZE - 1 && queue->front == 0;
}

// Function to insert an element at the rear of the queue
void enqueue(struct Queue *queue, int data)
{
    // check if the queue is full
    if (isFull(queue))
        return;

    // if the queue is empty, set the front and rear of the queue to the same index
    if (isEmpty(queue))
        queue->front = queue->rear = 0;

    // otherwise, increment the rear of the queue
    else
        queue->rear = (queue->rear + 1) % MAX_SIZE;

    queue->data[queue->rear] = data;
}

// Function to delete an element from the front of the queue
int dequeue(struct Queue *queue)
{
    // check if the queue is empty
    if (isEmpty(queue))
        return -1;

    // store the element at the front of the queue
    int item = queue->data[queue->front];

    // if the queue has only one element, set the front and rear of the queue to the same index
    if (queue->front == queue->rear)
        queue->front = queue->rear = 0;

    // otherwise, increment the front of the queue
    else
        queue->front = (queue->front + 1) % MAX_SIZE;

    return item;
}

// Function to reverse the elements of a queue
void reverseQueue(struct Queue *queue)
{
    // create a new queue
    struct Queue *temp = createQueue();

    // insert the elements of the queue at the front of the new queue
    while (!isEmpty(queue))
        enqueue(temp, dequeue(queue));

    // set the front and rear of the queue to the front and rear of the new queue
    queue->front = temp->front;
    queue->rear = temp->rear;

    // copy the elements of the new queue to the queue
    while (!isEmpty(temp))
        queue->data[queue->front + queue->rear++] = dequeue(temp);

    // free the memory used by the new queue
    free(temp);
}

// Function to test the queue implementation
int main()
{
    // create a new queue
    struct Queue *queue = createQueue();

    // insert elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // reverse the elements of the queue
    reverseQueue(queue);

    // print the elements of the queue
    printf("Queue: ");

    while (!isEmpty(queue))
        printf("%d ", dequeue(queue));

    return 0;
}
