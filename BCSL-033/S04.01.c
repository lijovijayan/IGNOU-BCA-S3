/*
Write a program in ‘C’ language to convert a prefix expression to a
postfix expression using pointers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a prefix expression to a postfix expression
void prefixToPostfix(char *prefix, char *postfix)
{
    // stack to store operators
    char stack[strlen(prefix)];

    // initialize top of stack
    int top = -1;

    // evaluate the expression
    for (int i = strlen(prefix) - 1; i >= 0; i--)
    {
        // push operands to the stack
        if (isalnum(prefix[i]))
            stack[++top] = prefix[i];

        // if the current character is an operator
        else
        {
            // pop two operands from the stack
            char op1 = stack[top--];
            char op2 = stack[top--];

            // create a string with the two operands and the operator
            // in the correct order (op1 op2 operator)
            char temp[3] = {op1, op2, prefix[i]};

            // push the result to the stack
            stack[++top] = strdup(temp);
        }
    }

    // copy the result from the stack to the postfix string
    strcpy(postfix, stack[top--]);
}

// main function
int main()
{
    // input prefix expression
    char prefix[] = "*-A/BC-/AKL";

    // output postfix expression
    char postfix[strlen(prefix)];

    // convert prefix to postfix expression
    prefixToPostfix(prefix, postfix);

    // print the postfix expression
    printf("%s", postfix);

    return 0;
}
