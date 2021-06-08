#include "customer.h"
#include <string.h>
#include <iomanip>
#include <iostream>

using namespace std;
typedef unsigned int u_int;

template <class T>
Customer<T>::Customer() : numberOfProducts(0), orderedProducts(nullptr){
    profileName = new char[1];
    profileName[0] = '\0';
    address = new char[1];
    address[0] = '\0';
}

template <class T>
Customer<T>::Customer(const char* _profileName,const char* _address, u_int _numberOfProducts, T* _orderedProducts)
//:
//    profileName(_profileName),
//    address(_address),
//    numberOfProducts(_numberOfProducts),
//    orderedProducts(_orderedProducts)
    {
    this->setProfileName(_profileName);
    this->setAddress(_address);
    this->setNumberOfProducts(_numberOfProducts);
    this->setOrderedProducts(_orderedProducts);
    }

template <class T>
Customer<T>::Customer(const Customer<T>& other){
    this->setProfileName(other.getProfileName());
    this->setAddress(other.getAddress());
    this->setNumberOfProducts(other.getNumberOfProducts());
    this->setOrderedProducts(other.getOrderedProducts());
}

template <class T>
Customer<T>& Customer<T>:: operator=(const Customer<T>& other) {
    if (this == &other) {
        return *this;
    } else {
        setProfileName(other.getProfileName());
        setAddress(other.getAddress());
        setNumberOfProducts(other.getNumberOfProducts());
        return *this;
    }
}

template <class T>
Customer<T>::~Customer(){
    delete[] this->profileName;
    delete[] this->address;
    delete[] this->orderedProducts;
}

template <class T>
void Customer<T>::setProfileName(const char* _profileName){
 //   delete[] this->profileName;
    this->profileName = new char[strlen(_profileName) + 1];
    strcpy(this->profileName, _profileName);
}

template <class T>
void Customer<T>::setAddress(const char* _address){
//    delete[] this->address;
    this->address = new char[strlen(_address) + 1];
    strcpy(this->address, _address);
}

template <class T>
void Customer<T>::setNumberOfProducts(u_int _numberOfProducts){
    this->numberOfProducts = _numberOfProducts;
}

template <class T>
void Customer<T>::setOrderedProducts(const T* _orderedProducts) {
 //   delete[] this->orderedProducts;
    this->orderedProducts = new T[maxOfProducts];
    for (u_int i = 0; i < numberOfProducts; i++) {
        orderedProducts[i] = _orderedProducts[i];
    }
}

template <class T>
const char* Customer<T>::getProfileName() const {
    return this->profileName;
}

template <class T>
const char* Customer<T>::getAddress() const {
    return this->address;
}

template <class T>
int Customer<T>::getNumberOfProducts() const{
    return this->numberOfProducts;
}

template <class T>
T* Customer<T>::getOrderedProducts() const{
    return this->orderedProducts;
}

template <class T>
void Customer<T>::addProducts(const T& newOrder) {
    //delete[] this->orderedProducts
    T* _orderedProducts = new T[numberOfProducts + 1];
    for (u_int i = 0; i < numberOfProducts; i++) {
        _orderedProducts[i] = orderedProducts[i];
    }
    numberOfProducts++;

    orderedProducts = new T [numberOfProducts + 1];
    for (u_int i = 0; i < numberOfProducts - 1; i++) {
        orderedProducts[i] = _orderedProducts[i];
    }
    orderedProducts[numberOfProducts-1] = newOrder;
    delete[] _orderedProducts;
}

template <class T>
void Customer<T>::removeProducts(u_int index) {
    if(index > numberOfProducts){
        cout << "incorect index of product to delete" << endl;
    }
    for(u_int i = 0; i < numberOfProducts; i++){
        for(u_int j = index + 1; j < numberOfProducts; j++){
            orderedProducts[index] = orderedProducts[j];
        }
    }
    numberOfProducts--;
}

template <class T>
void Customer<T>::resizeMethod(){
    if(numberOfProducts == maxOfProducts){
        maxOfProducts+= 5;
    }
}

template <class T>
void Customer<T>::Print() const {
    cout << "Profile name of customer: "<< this->profileName << "; Address for delivery: " << this->address
    << "; " << endl;
    cout << endl;
    cout << "Ordered Products: " <<endl;
    for (u_int i = 0; i < numberOfProducts; i++){
        cout << "\t";
        orderedProducts[i].Print();
    }
}

template <class T>
void Customer<T>::ChangeProfileName(char* newName){
    this->profileName = newName;
    cout << "The new profile name is " << profileName << ";" << endl;
    cout << endl;
}

template <class T>
void Customer<T>::ChangeAddress(char* newAddress){
    this->address = newAddress;
    cout << "The new delivery address is" << address << ";" << endl;
    cout << endl;
}

template <class T>
void Customer<T>::ChangenumberOfProducts(u_int newNumber){
    this->numberOfProducts = newNumber;
    cout << "Number of orders" << numberOfProducts << ";" << endl;
    cout << endl;
}
