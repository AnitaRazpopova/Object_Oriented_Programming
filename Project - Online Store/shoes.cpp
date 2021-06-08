#include <string.h>
#include <iomanip>
#include "shoes.h"

Shoes::Shoes() : price(0){
    brand = new char[1];
    brand[0] = '\0';
    type = new char[1];
    type[0] = '\0';
    colour = new char[1];
    colour[0] = '\0';
}

Shoes::Shoes(const char* _brand,const char* _type, double _price,u_int _sizeS,const  char* _colour)
//:
//    brand(_brand),
//    type(_type),
//    price(_price),
//    sizeS(_sizeS),
//    colour(_colour)
    {
    this->setBrand(_brand);
    this->setType(_type);
    this->setPrice(_price);
    this->setSizeS(_sizeS);
    this->setColour(_colour);
    }

Shoes::Shoes(const Shoes& other){
    this->setBrand(other.getBrand());
    this->setType(other.getType());
    this->setPrice(other.getPrice());
    this->setSizeS(other.getSizeS());
    this->setColour(other.getColour());
}

Shoes& Shoes:: operator=(const Shoes& other) {
    if (this == &other) {
        return *this;
    } else {
        setBrand(other.getBrand());
        setType(other.getType());
        setPrice(other.getPrice());
        setSizeS(other.getSizeS());
        setColour(other.getColour());
        return *this;
    }
}

Shoes::~Shoes(){
    //cout << "shoes destructor called" << endl;
    delete[] this->brand;
    delete[] this->type;
    delete[] this->colour;
}
void Shoes::setBrand(const char* _brand){
//    delete[] this->brand;
    this->brand = new char[strlen(_brand) + 1];
    strcpy(this->brand, _brand);
}

void Shoes::setType(const char* _type){
//    delete[] this->type;
    this->type = new char[strlen(_type) + 1];
    strcpy(this->type, _type);
}

void Shoes::setPrice(double _price) {
    this->price = _price;
}

void Shoes::setSizeS(int _sizeS){
    this->sizeS = _sizeS;
}

void Shoes::setColour(const char* _colour){
//    delete[] this->colour;
    this->colour = new char[strlen(_colour) + 1];
    strcpy(this->colour, _colour);
}

const char* Shoes::getBrand() const {
    return this->brand;
}

const char* Shoes::getType() const {
    return this->type;
}

double Shoes::getPrice() const {
    return this->price;
}

int Shoes::getSizeS() const {
    return this->sizeS;
}

const char* Shoes::getColour() const {
    return this->colour;
}

void Shoes::Print() const {
    cout << "Product from delivery order: "<< this->brand << "; type: " << this->type << "; price:"
    << fixed <<setprecision(2) << this->price << " leva; " << "size:"
    << this->sizeS << "; Colour:" << this->colour << ";" << endl;
    cout << endl;
}

void Shoes::MakeProductDiscount(double discountProcent){
    this->price = price - (discountProcent/100)*price;
    cout << "The client has " << discountProcent << "% discount and the new price is: "<< fixed << setprecision(2)
     << price << " leva" << ";" << endl;
    cout << endl;
}

void Shoes::ChangeColour(char* newColour){
    this->colour = newColour;
    cout << "The new colour of the product the client has ordered is - " << colour << ";" << endl;
    cout << endl;
}

void Shoes::ChangeSize(u_int newSize){
    if(newSize < 36 && newSize > 46){
        cout << "The shoe size is not available" << endl;
    } else {
        this->sizeS = newSize;
        cout << "The client has ordered another size: " << sizeS << ";" << endl;
        cout << endl;
    }
}

