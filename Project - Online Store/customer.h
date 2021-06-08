#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include "customer.h"

typedef unsigned int u_int;
template<class T>
class Customer{

private:
    char* profileName;
    char* address;
    u_int maxOfProducts = 15;
    u_int numberOfProducts;
    T* orderedProducts;
    void resizeMethod();

public:
    Customer();

    Customer(const char* _profileName,const  char* _address, u_int _numberOfProducts, T* orderedProducts);

    Customer& operator=(const Customer& other);

    Customer(const Customer& other);

    ~Customer();

    void setProfileName(const char* _profileName);

    void setAddress(const char* _address);

    void setNumberOfProducts(u_int _numberOfProducts);

    void setOrderedProducts(const T* _orderedProducts);

    const char* getProfileName() const;

    const char* getAddress() const;

    int getNumberOfProducts() const;

    T* getOrderedProducts() const;

    void addProducts(const T& newOrder);

    void removeProducts(u_int index);

    void Print() const ;

    void ChangeProfileName(char* newName);

    void ChangeAddress(char* newAddress);

    void ChangenumberOfProducts(u_int newNumber);
};


#endif // CUSTOMER_H_INCLUDED
