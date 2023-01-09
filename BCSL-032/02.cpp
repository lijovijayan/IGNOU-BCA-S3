// Program to Check if a given number is Prime or not:

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
class Prime
{
private:
    int n;

public:
    void getdata();
    void calculate();
};
void Prime ::getdata()
{
    cout << "Enter number ";
    cin >> n;
}
void Prime ::calculate()
{
    int i;
    for (i = 2; i <= n / 2; i++)
        if (n % i == 0)

        {
            cout << "NOT PRIME";
            getch();
            exit(0);
        }
    cout << "PRIME";
}

void main()
{
    clrscr();
    Prime p;
    p.getdata();
    p.calculate();
    getch();
}

// Output
// Enter number : 7 PRIME
// Enter number : 10 PRIME