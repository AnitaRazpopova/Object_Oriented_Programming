#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include <iostream>
#include <cmath>

using namespace std;

class Rectangle{

private:
    double x1;
    double y1;
    double x2;
    double y2;
    double S;
    double a;
    double b;

    void setA(double _x1, double _x2);

    void setB(double _y1, double _y2);

    void setS() ;

public:

    Rectangle() = default;

    Rectangle(double _x1, double _y1, double _x2, double _y2);

    void setX1(double _x1);

    double getX1() const;

    void setY1(double _y1);

    double getY1() const;

    void setX2(double _x2);

    double getX2() const;

    void setY2(double _y2);

    double getY2() const;

    double getA() const;

    double getB() const;

    double getS() const;

    void print() const;
};


#endif // RECTANGLE_H_INCLUDED
