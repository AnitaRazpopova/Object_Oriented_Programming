#include <string.h>
#include <iomanip>
#include "clothes.h"

Clothes::Clothes(): price(0){
    brand = new char[1];
    brand[0] = '\0';
    sizeC = new char[1];
    sizeC[0] = '\0';
    colour = new char[1];
    colour[0] = '\0';
}

Clothes::Clothes(const char* _brand, TypeClothes _type, double _price,const char* _sizeC, const char* _colour)
//:
//    brand(_brand),
//    type(_type),
//    price(_price),
//    sizeC(_sizeC),
//    colour(_colour)
    {
    this->setBrand(_brand);
    this->setType(_type);
    this->setPrice(_price);
    this->setSizeC(_sizeC);
    this->setColour(_colour);
}

Clothes::Clothes(const Clothes& other){
    this->setBrand(other.getBrand());
    this->setType(other.getType());
    this->setPrice(other.getPrice());
    this->setSizeC(other.getSizeC());
    this->setColour(other.getColour());
}

Clothes& Clothes:: operator=(const Clothes& other) {
    if (this == &other) {
        return *this;
    } else {
        setBrand(other.getBrand());
        setType(other.getType());
        setPrice(other.getPrice());
        setSizeC(other.getSizeC());
        setColour(other.getColour());
        return *this;
    }
}

Clothes::~Clothes(){
    //cout << "clothes destructor called" << endl;
    delete[] this->brand;
    delete[] this->sizeC;
    delete[] this->colour;
}

void Clothes::setBrand(const char* _brand){
    delete[] this->brand;
    this->brand = new char[strlen(_brand) + 1];
    strcpy(this->brand, _brand);
}

void Clothes::setType(TypeClothes _type){
    this->type = _type;
}

void Clothes::setPrice(double _price) {
    this->price = _price;
}

void Clothes::setSizeC(const char* _sizeC){
//    delete[] this->sizeC;
    this->sizeC = new char[strlen(_sizeC) + 1];
    strcpy(this->sizeC, _sizeC);
}

void Clothes::setColour(const char* _colour){
//    delete[] this->colour;
    this->colour = new char[strlen(_colour) + 1];
    strcpy(this->colour, _colour);
}

const char* Clothes::getBrand() const {
    return this->brand;
}

TypeClothes Clothes::getType() const {
    return this->type;
}

const char* Clothes::getTypeAsString() const{
    switch (type){
        case shirt:
            return "shirt";
            break;
        case skirt:
            return "skirt";
            break;
        case pants:
            return "pants";
            break;
        case sweater:
            return "sweater";
            break;
        case blazer:
            return "blazer";
            break;
        case jeans:
            return "jeans";
            break;
        case jacket:
            return"jacket";
            break;
        case coat:
            return "coat";
            break;
        default:
            return "\0";
            break;
    }
}

double Clothes::getPrice() const {
    return this->price;
}

const char* Clothes::getSizeC() const {
    return this->sizeC;
}

const char* Clothes::getColour() const {
    return this->colour;
}

void Clothes::Print() const {
    cout << "Product from delivery order: " << this->brand << "; type: " << this->getTypeAsString();
    cout << "; price: " << fixed << setprecision(2) << this->price << " leva; " << "size: " << this->sizeC
    << "; colour: " << this->colour << ";" << endl;
    cout << endl;
}

void Clothes::MakeProductDiscount(double discountProcent){
    this->price = price - (discountProcent/100)*price;
    cout << "The client has " << discountProcent << "% discount and the new price is: "<< fixed << setprecision(2)
     << price << " leva" << ";" << endl;
    cout << endl;
}

void Clothes::ChangeColour(char* newColour){
    this->colour = newColour;
    cout << "The newColour is - " << colour << ";" << endl;
    cout << endl;
}

void Clothes::ChangeSize(char* newSize){
    if(strcmp(newSize, "XS") != 0 && strcmp(newSize, "S") != 0
       && strcmp(newSize, "M") != 0 && strcmp(newSize, "L") != 0 && strcmp(newSize,"XL") != 0){
        cout << "invalid size" << endl;
    }
    else {
        this->sizeC = newSize;
        cout << "The client has ordered another size: " << sizeC  << ";" << endl;
        cout << endl;
    }
}
