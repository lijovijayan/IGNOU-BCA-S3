/*
Write a program in ‘C’ language to implement a queue using two stacks.
*/

#include <stdio.h>
#include <stdlib.h>

// Stack data structure
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Function to create a stack of given capacity
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top--];
}

// Queue data structure
struct Queue
{
    struct Stack *stack1;
    struct Stack *stack2;
};

// Function to create a queue
struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to enqueue an item
void enqueue(struct Queue *queue, int item)
{
    push(queue->stack1, item);
}

// Function to dequeue an item
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2))
    {
        return -1;
    }

    // If stack2 is empty, move items from stack1 to stack2
    if (isEmpty(queue->stack2))
    {
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    // Return the top item from stack2
    return pop(queue->stack2);
}

int main()
{
    // Create a queue of capacity 4
    struct Queue *queue = createQueue(4);

    // Enqueue items
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    // Dequeue items
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    return 0;
}
