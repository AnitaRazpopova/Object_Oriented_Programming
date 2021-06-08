#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <iostream>
#include "Rectangle.h"
using namespace std;

class SVG{

private:
    Rectangle* rectangles;
    int numOfAddedRectangles;

public:
    SVG(): rectangles(nullptr), numOfAddedRectangles(0){};

    SVG(int _numOfAddedRectangles, Rectangle* _rectangles);

    SVG(const SVG& other);

    SVG operator=(const SVG& other);

    ~SVG();

    void setRectangles(const Rectangle* _rectangles);

	Rectangle* getRectangles() const;

    void addRectangle(const Rectangle& rectangle);

    int getNumOfAddedRectangles()const;

    void setNumOfAddedRectangles(int _numOfAddedRectangles);

    void print()const;

    double FindIndexOfBiggestRectangle() const;

};

#endif // SVG_H_INCLUDED
