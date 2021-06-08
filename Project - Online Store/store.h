#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include "store.h"
#include "customer.h"

typedef unsigned int u_int;
template<class T>
class Store{
private:
    char* name;
    u_int numberOfProducts;
    u_int maxOfProducts = 15;
    T* products;
    void resizeMethodProducts();

public:
    Store();
    Store(char* _name, u_int _numberOfProducts, T* _products );
    Store(const Store& other);
    Store& operator=(const Store& other);
   ~Store();

    void setName(const char* _name);
    const char* getName() const;
    void setNumberOfProducts(u_int _numberOfProducts);
    int getNumberOfProducts() const;
    void setProducts(const T* _products);
    T* getProducts() const;
    void addProducts(const T& newOrder);
    void removeProducts(int index);
    void ChangeName(char* newName);

    void Print() const;
};



#endif // STORE_H_INCLUDED
