#include <iostream>

#include "intCounter.h"

IntCounter::IntCounter() = default;

IntCounter::IntCounter(int* _number) {
    this->setNumber(_number);
    this->setCounter(1);
    this->pCounter = &counter;
}

IntCounter::IntCounter(const IntCounter& other){
    this->setNumber(other.getNumber());
    this->setCounter(0);
    this->setPCounter(other.getPCounter());
    *(pCounter) = *(pCounter) + 1;
}

IntCounter IntCounter::operator=(const IntCounter& other){
    if(this == &other){
        return *this;
    } else {
        this->setNumber(other.getNumber());
        this->setCounter(0);
        this->setPCounter(other.getPCounter());
        *(pCounter) = *(pCounter) + 1;
        return *this;
    }

}

void IntCounter::setNumber(int* _number){
    this->number = _number;
}
int* IntCounter::getNumber() const {
    return this->number;
}

void IntCounter::setCounter(int _counter) {
    this->counter = _counter;
}
int IntCounter::getCounter() const {
    return this->counter;
}

void IntCounter::setPCounter(int* _pCounter){
    this->pCounter = _pCounter;
}
int* IntCounter::getPCounter() const {
    return this->pCounter;
}

int IntCounter::get_number() const { //returns the value of the variable
    return *(number);
}

int IntCounter::get_count() const {  //returns the value of the variable
    return *(pCounter);
}

IntCounter::~IntCounter() {
    *(pCounter) = *(pCounter) - 1;
    if (counter == 0) {
        delete this->number;
    }
}
