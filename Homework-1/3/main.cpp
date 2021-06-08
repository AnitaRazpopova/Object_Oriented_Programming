#include <iostream>
#include <cmath>
#include "Rectangle.h"
#include "SVG.h"

using namespace std;

int main()
{
    Rectangle r4(7, 4, 5, 1);
    Rectangle r1(1, 2, 3, 4);
    Rectangle r2(0, 0, 2, 2);
    Rectangle r3(0, 0, 10, 10);
//    r4.print();
//    cout << r4.getS();
    Rectangle* rectangles = new Rectangle[0];

    SVG Vector(0, rectangles);
    Vector.addRectangle(r1);
//    Vector.print();
    Vector.addRectangle(r2);
    Vector.addRectangle(r3);
    Vector.addRectangle(r4);
    Vector.print();
    Vector.FindIndexOfBiggestRectangle();

    return 0;
}
