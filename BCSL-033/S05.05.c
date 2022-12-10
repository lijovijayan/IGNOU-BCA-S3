/*
Write a program in ‘C’ language to implement a stack using two queues.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// queue data structure
typedef struct queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// stack data structure
typedef struct stack
{
    Queue *q1;
    Queue *q2;
} Stack;

// create a new queue
Queue *create_queue()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// create a new stack
Stack *create_stack()
{
    Stack *s = malloc(sizeof(Stack));
    s->q1 = create_queue();
    s->q2 = create_queue();
    return s;
}

// check if the stack is empty
int is_empty(Stack *s)
{
    return (s->q1->front == -1 && s->q1->rear == -1);
}

// push an element onto the stack
void push(Stack *s, int data)
{
    // first, add the element to q1
    s->q1->data[++s->q1->rear] = data;

    // now, move all the elements from q1 to q2
    while (s->q1->front <= s->q1->rear)
    {
        s->q2->data[++s->q2->rear] = s->q1->data[s->q1->front++];
    }

    // swap the names of q1 and q2
    Queue *temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    // reset the front and rear pointers of q2
    s->q2->front = -1;
    s->q2->rear = -1;
}

// pop an element from the stack
int pop(Stack *s)
{
    // return the top element from q1
    return s->q1->data[s->q1->front++];
}

// main function
int main()
{
    Stack *s = create_stack();

    // push some elements onto the stack
    push(s, 1);
    push(s, 2);
    push(s, 3);

    // pop and print the elements from the stack
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));

    return 0;
}
