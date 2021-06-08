#include "Rectangle.h"

void Rectangle::setA(double _x1, double _x2){
    this->a = abs(getX1() - getX2());
}

void Rectangle::setB(double _y1, double _y2){
    this->b = abs(getY1() - getY2());
}
void Rectangle::setS() {
    this->S = getA()*getB();
}


Rectangle::Rectangle(double _x1, double _y1, double _x2, double _y2) :
    x1(_x1),
    y1(_y1),
    x2(_x2),
    y2(_y2){
        setA(_x1, _x2);
        setB(_y1, _y2);
        setS();

    }

void Rectangle::setX1(double _x1){
    this->x1 = _x1;
}

double Rectangle::getX1() const{
    return this->x1;
}

void Rectangle::setY1(double _y1){
    this->y1 = _y1;
}

double Rectangle::getY1() const{
    return this->y1;
}

void Rectangle::setX2(double _x2){
    this->x2 = _x2;
}

double Rectangle::getX2() const {
    return this->x2;
}

void Rectangle::setY2(double _y2){
    this->y2 = _y2;
}

double Rectangle::getY2() const{
    return this->y2;
}

double Rectangle::getA() const{
    return this->a;
}

double Rectangle::getB() const{
    return this->b;
}

double Rectangle::getS() const{
    return this->S;
}

void Rectangle::print() const{
    for(int i = 0; i < getB(); i++){
        for(int j = 0; j < getA(); j++){
            cout << "* " ;
        }
        cout << endl;
    }
    cout <<"a =" << a << " b ="<< b << endl;
    cout << endl;
}
