#ifndef CLOTHES_H_INCLUDED
#define CLOTHES_H_INCLUDED
#include <iostream>
using namespace std;

enum TypeClothes{ shirt, skirt, pants, sweater, blazer, jeans, jacket, coat};

class Clothes{

private:

    char* brand;
    TypeClothes type; //t-shirt,shirt,skirt,jacket
    double price;
    char* sizeC;
    char* colour;

public:

    Clothes();
    Clothes(const  char* _brand, TypeClothes _type, double _price,const  char* _sizeC,const char* _colour);

    Clothes(const Clothes& other);

    Clothes& operator=(const Clothes& other);

    ~Clothes();

    void setBrand(const char* _brand);

    void setType(TypeClothes _type);

    void setPrice(double _price);

    void setSizeC(const char* _sizeC);

    void setColour(const char* _colour);

    const char* getBrand() const ;

    TypeClothes getType() const ;

    const char* getTypeAsString() const;

    double getPrice() const;

    const char* getSizeC() const;

    const char* getColour() const;

    void Print() const;

    void MakeProductDiscount(double discountProcent);

    void ChangeColour(char* newColour);

    void ChangeSize(char* newSize);
};



#endif // CLOTHES_H_INCLUDED
