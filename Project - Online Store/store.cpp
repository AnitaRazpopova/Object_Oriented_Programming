#include "store.h"
#include <iostream>
#include <string.h>

using namespace std;
template <class T>
Store<T>::Store() : numberOfProducts(0),products(nullptr) {
    name = new char[1];
    name[0] = '\0';
}

template <class T>
Store<T>::Store( char* _name, u_int _numberOfProducts, T* _products ):
    name(_name), numberOfProducts(_numberOfProducts), products(_products){
}

template <class T>
Store<T>::Store(const Store<T>& other){
    this->setName(other.getName());
    this->getNumberOfProducts(other.getNumberOfProducts());
    this->getNumberOfCustomers(other.getNumberOfCustomers());
    this->setProducts(other.getProducts());

}

template <class T>
Store<T>& Store<T>:: operator=(const Store<T>& other) {
    if (this == &other) {
        return *this;
    } else {
        this->setName(other.getName());
        this->getNumberOfProducts(other.getNumberOfProducts());
        this->getNumberOfCustomers(other.getNumberOfCustomers());
        this->setProducts(other.getProducts());
        return *this;
    }
}

template <class T>
Store<T>::~Store(){
    //cout << "store destructor called" << endl;
    delete[] this->name;
//    delete[] this->products;
//    delete[] this->customers;
}

template <class T>
void Store<T>::setName(const char* _name){
 //   delete[] this->name;
    this-> name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

template <class T>
const char* Store<T>::getName() const{
    return this->name;
}

template <class T>
void Store<T>::setNumberOfProducts(u_int _numberOfProducts){
    this->numberOfProducts = _numberOfProducts;
}

template <class T>
int Store<T>::getNumberOfProducts() const{
    return this->numberOfProducts;
}


template <class T>
void Store<T>::setProducts(const T* _products) {
 //   delete[] this->orderedProducts;
    this->products = new T[maxOfProducts];
    for (u_int i = 0; i < maxOfProducts; i++) {
        products[i] = _products[i];
    }
}

template <class T>
T* Store<T>::getProducts() const{
    return this->products;
}

template <class T>
void Store<T>::addProducts(const T& newOrder) {
    //delete[] this->products
    T* _products = new T[numberOfProducts + 1];
    for (u_int i = 0; i < numberOfProducts; i++) {
        _products[i] = products[i];
    }
    numberOfProducts++;

    products = new T [numberOfProducts + 1];
    for (u_int i = 0; i < numberOfProducts - 1; i++) {
        products[i] = _products[i];
    }
    products[numberOfProducts-1] = newOrder;
    delete[] _products;
}

template <class T>
void Store<T>::removeProducts(int index) {
    if(index > numberOfProducts){
        cout << "incorect index of product to delete" << endl;
    }
    for(u_int i = 0; i < numberOfProducts; i++){
        for(int j = index + 1; j < numberOfProducts; j++){
            products[index] = products[j];
        }
    }
    numberOfProducts--;
}

template <class T>
void Store<T>::resizeMethodProducts(){
    if(numberOfProducts == maxOfProducts){
        maxOfProducts+= 5;
    }
}
template <class T>
void Store<T>::ChangeName(char* newName){
    this->name = newName;
    cout << "The new name of the store is - " << name << ";" << endl;
    cout << endl;
}

template <class T>
void Store<T>::Print() const {
    cout << "Name of store: "<< this->name << "; " << endl;
    cout << "Products of the store: " << endl;
    cout << endl;
    for (u_int i = 0; i < numberOfProducts; i++){
        cout << "\t";
        products[i].Print();
    }

}
