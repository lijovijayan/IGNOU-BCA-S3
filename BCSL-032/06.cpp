// Program to demonstrate Inheritance

#include <iostream.h>
#include <conio.h>

    // Base class
    class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }

protected:
    int width;
    int height;
};

// Derived class
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};

void main(void)
{
    clrscr();
    Rectangle Rect;

    Rect.setWidth(5);
    Rect.setHeight(7);

    // Print the area of the object.
    cout << "Total area: " << Rect.getArea() << endl;

    getch();
}

// Output:
// Total area : 35