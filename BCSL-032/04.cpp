// Program to find the product of 2 matrices :
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
class PRODUCT
{
private:
    int a[20][20], b[20][20], p[20][20], i, j, k, m1, n1, m2, n2;

public:
    void getorder();
    void confirmation();
    void getdata();
    void findproduct();
    void display();
};

void PRODUCT ::getorder()
{
    cout << "\nEnter the order of the matrix-1   \n";
    cin >> m1 >> n1;
    cout << "\nEnter the order of the matrix-2   \n";
    cin >> m2 >> n2;
}
void PRODUCT ::confirmation()
{
    if (n1 != m2)
    {
        cout << "NOT CONFIRMABLE FOR MULTIPLICATION";
        getch();
        exit(0);
    }
}
void PRODUCT ::getdata()
{
    /*Read First matrix*/
    cout << "Enter the matrix-1 elements   \n";
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            cin >> a[i][j];
    /*Read Second matrix*/
    cout << "Enter the matrix-2 elements   \n";
    for (i = 0; i < m2; i++)
        for (j = 0; j < n2; j++)
            cin >> b[i][j];
}
void PRODUCT ::findproduct()
{
    /*Product of 2 matrices*/
    for (i = 0; i < m1; i++)
        for (j = 0; j < n2; j++)
            for (k = 0, p[i][j] = 0; k < n1; k++)
                p[i][j] = p[i][j] + a[i][k] * b[k][j];
}
void PRODUCT ::display()
{
    cout << "\nThe First matrix is \n\n";
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
            cout << a[i][j] << "\t";
        cout << "\n\n";
    }
    cout << "\nThe Second matrix is \n\n";
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
            cout << b[i][j] << "\t";
        cout << "\n\n";
    }
    cout << "\nThe Product matrix is \n\n";
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
            cout << p[i][j] << "\t";
        cout << "\n\n";
    }
}

void main()
{
    clrscr();
    PRODUCT p;
    p.getorder();
    p.confirmation();
    p.getdata();
    p.findproduct();
    p.display();
    getch();
}

// OUTPUT :

// Enter the order of the matrix - 1 
// 2 2

// Enter the order of the matrix - 2 
// 4 2 

// NOT CONFIRMABLE FOR MULTIPLICATION

// -----------------------------------------------------------------------

// Enter the order of the matrix - 1 
// 2 3

// Enter the order of the matrix - 2 
// 3 2 
// Enter the matrix - 1 elements 
// 1 1 1 1 1 1 
// Enter the matrix - 2 elements 
// 3 3 3 3 3 3

// The First matrix is
// 1 1 1
// 1 1 1

// The Second matrix is
// 3 3
// 3 3
// 3 3

// The Product matrix is
// 9 9
// 9 9