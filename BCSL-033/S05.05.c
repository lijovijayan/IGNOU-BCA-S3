/*
Write a program in ‘C’ language to implement a stack using two queues.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* queue structure */
struct queue {
    int data[MAX_SIZE];
    int front;
    int rear;
};

/* stack structure */
struct stack {
    struct queue q1;
    struct queue q2;
};

/* push operation for stack */
void push(struct stack *s, int x)
{
    if (s->q1.rear == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        return;
    }

    s->q1.data[++s->q1.rear] = x;
}

/* pop operation for stack */
int pop(struct stack *s)
{
    int i, x;

    if (s->q1.front > s->q1.rear) {
        printf("Error: stack underflow\n");
        return -1;
    }

    /* move all elements from q1 to q2 except the last element */
    while (s->q1.front < s->q1.rear) {
        x = s->q1.data[s->q1.front++];
        s->q2.data[++s->q2.rear] = x;
    }

    /* store the last element of q1 */
    x = s->q1.data[s->q1.front];

    /* reset q1 */
    s->q1.front = 0;
    s->q1.rear = -1;

    /* move all elements back from q2 to q1 */
    while (s->q2.front <= s->q2.rear) {
        s->q1.data[++s->q1.rear] = s->q2.data[s->q2.front++];
    }

    /* reset q2 */
    s->q2.front = 0;
    s->q2.rear = -1;

    return x;
}

/* main function */
int main(void)
{
    struct stack s;
    int i;

    s.q1.front = 0;
    s.q1.rear = -1;
    s.q2.front = 0;
    s.q2.rear = -1;

    printf("Pushing element 1\n");
    push(&s, 1);

    printf("Pushing element 2\n");
    push(&s, 2);
    
    printf("Pushing element 3\n\n");
    push(&s, 3);

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    return 0;
}

// Output:

// Pushing element 1
// Pushing element 2
// Pushing element 3

// Popped element: 3
// Popped element: 2
// Popped element: 1