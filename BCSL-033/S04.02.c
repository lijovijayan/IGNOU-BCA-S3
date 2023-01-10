/*
Write a program in ‘C’ language to reverse an input string.
*/

#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse(char *str)
{
    // find the length of the string
    int length = strlen(str), i = 0;

    // loop through the string
    for (i = 0; i < length / 2; i++)
    {
        // swap the characters at the beginning and end of the string
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// main function
int main()
{
    char str[100];

    printf("Enter a string: ");

    // input string
    fgets(str, sizeof(str), stdin);

    // reverse the string

    reverse(str);

    // print the reversed string
    printf("Reverse of the string: %s", str);

    return 0;
}

// Output:

// Enter a string: Hello world!
// Reverse of the string: 
// !dlrow olleH