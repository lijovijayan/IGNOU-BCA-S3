// Program to implement Complex Number Addition

#include <iostream.h>
#include <conio.h>

class COMPLEX
{
private:
    int realp;
    int imgp;

public:
    void readValues(void)
    {
        cout << "Enter the real part and imaginary part" << endl;
        cin >> realp >> imgp;
    }

    friend COMPLEX ADD(COMPLEX, COMPLEX);
    friend COMPLEX ADD(int, COMPLEX);
    friend ostream &operator<<(ostream &, COMPLEX &);
};

COMPLEX ADD(COMPLEX s1, COMPLEX s2) // To add two COMPLEX objects
{
    COMPLEX c;
    c.realp = s1.realp + s2.realp;
    c.imgp = s1.imgp + s2.imgp;
    return c;
}

COMPLEX ADD(int ival, COMPLEX s2) // To add an int to COMPLEX object
{
    COMPLEX c;
    c.realp = ival + s2.realp;
    c.imgp = s2.imgp;
    return c;
}

// Member function to overload <<
ostream &operator<<(ostream &out, COMPLEX &comp)
{
    out << comp.realp << " +i " << comp.imgp << endl;
    return out;
}

void main()
{
    COMPLEX C1, C2, C3;
    int choice, ival;
    clrscr();

    cout << "1. To add two complex objects" << endl;
    cout << "2. To add real part to a complex object" << endl;
    cout << "Please enter your choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        C1.readValues();
        C2.readValues();
        cout << "\nC1 = " << C1;
        cout << "C2 = " << C2;
        cout << "-----------" << endl;
        C3 = ADD(C1, C2);
        cout << "C3 = " << C3;
        break;
    case 2:
        cout << "Enter an integer" << endl;
        cin >> ival;
        COMPLEX C4;
        C1.readValues();
        cout << "\nival = " << ival << endl;
        cout << "C1   = " << C1;
        cout << "----------------" << endl;
        C4 = ADD(ival, C1);
        cout << "C4   = " << C4;
        break;
    default:
        cout << "Error in input" << endl;
        break;
    }
}

// Output
// 1. To add two complex objects
// 2. To add real part to a complex object
// Please enter your choice: 1

// Enter the real part and imaginary part 2 3
// Enter the real part and imaginary part 4 5

// C1 = 2 + i 3 C2 = 4 + i 5 -- -- -- -- -- -C3 = 6 + i 8

// RUN2

// 1. To add two complex objects
// 2. To add real part to a complex object
// Please enter your choice: 2

// Enter an integer 13
// Enter the real part and imaginary part 12 45

// ival = 13 C1 = 12 + i 45 -- -- -- -- -- -- -- --C4 = 25 + i 45
