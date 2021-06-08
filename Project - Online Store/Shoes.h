#ifndef SHOES_H_INCLUDED
#define SHOES_H_INCLUDED
#include <iostream>
using namespace std;
typedef unsigned int u_int;

class Shoes{

private:
    char* brand;
    char* type; //t-shirt,shirt,skirt,jacket
    double price;
    u_int sizeS;
    char* colour;

public:
    Shoes();

    Shoes(const char* _brand,const char* _type, double _price,u_int _sizeS,const  char* _colour);

    Shoes(const Shoes& other);

    Shoes& operator=(const Shoes& other);

    ~Shoes();

    void setBrand(const char* _brand);

    void setType(const char* _type);

    void setPrice(double _price);

    void setSizeS(int _sizeS);

    void setColour(const char* _colour);

    const char* getBrand() const ;

    const char* getType() const;

    double getPrice() const;

    int getSizeS() const;

    const char* getColour() const;

    void Print() const ;

    void MakeProductDiscount(double discountProcent);

    void ChangeColour(char* newColour);

    void ChangeSize(u_int newSize);
};


#endif // SHOES_H_INCLUDED
