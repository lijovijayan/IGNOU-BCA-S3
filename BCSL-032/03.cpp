// Program to Check if a given String is Palindrome or not :

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

class Palindrom
{
private:
    char a[20], len;

public:
    void getdata();
    void findlength();
    void putdata();
};

void Palindrom ::getdata()
{
    char ch;
    int i;
    cout << "Enter the string ";
    for (i = 0; (ch = getchar()) != '\n'; i++)
        a[i] = ch;
    a[i] = '\0';
}

void Palindrom ::findlength()
{
    int i;
    for (i = 0; a[i] != '\0'; i++)
        ;
    len = i;
}

void Palindrom ::putdata()
{
    int i;
    for (i = 0; i < len / 2; i++)
        if (a[i] != a[len - i - 1])
        {
            cout << "NOT PALINDROME";
            getch();
            exit(0);
        }
    cout << "PALINDROME";
}

void main()
{
    clrscr();
    Palindrom p;
    p.getdata();
    p.findlength();
    p.putdata();
    getch();
}
// Output
// Enter the string
// MALAYALAM
// PALINDROME
// Enter the string
// COLLEGE
// NOT PALINDROME