/*
Write a program in ‘C’ language to implement multiple stacks in a
single array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACKS 10
#define MAX_SIZE 100

// Structure to represent a stack
struct Stack
{
    // array to store stack elements
    int data[MAX_SIZE];

    // top of stack
    int top;
};

// Function to create a new stack
struct Stack *createStack()
{
    // allocate memory for the stack
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    // initialize top of stack
    stack->top = -1;

    return stack;
}

// Function to check if the stack is full
bool isFull(struct Stack *stack)
{
    // check if the top of the stack is at the last index
    return stack->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack)
{
    // check if the top of the stack is at the first index
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack *stack, int item)
{
    // check if the stack is full
    if (isFull(stack))
        return;

    // increment the top of the stack and add the element
    stack->data[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    // check if the stack is empty
    if (isEmpty(stack))
        return -1;

    // return the top element and decrement the top of the stack
    return stack->data[stack->top--];
}

// main function
int main()
{
    // array of stacks
    struct Stack *stacks[MAX_STACKS];

    int i = 0, j = 0;

    // create 10 stacks
    for (i = 0; i < MAX_STACKS; i++)
        stacks[i] = createStack();

    // push some elements to the stacks
    for (i = 0; i < MAX_STACKS; i++)
    {
        for (j = 0; j < 5; j++)
            push(stacks[i], (i + 1) * (j + 1));
    }

    // pop some elements from the stacks
    for (i = 0; i < MAX_STACKS; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%d ", pop(stacks[i]));

        printf("\n");
    }

    return 0;
}

// Output:

// 5 4 3 2 1 
// 10 8 6 4 2 
// 15 12 9 6 3 
// 20 16 12 8 4 
// 25 20 15 10 5 
// 30 24 18 12 6 
// 35 28 21 14 7 
// 40 32 24 16 8 
// 45 36 27 18 9 
// 50 40 30 20 10