#ifndef INTCOUNTER_H_INCLUDED
#define INTCOUNTER_H_INCLUDED

#include <iostream>
#include <cstddef>

class IntCounter{

private:
    int* number;
    int counter;
    int* pCounter;

public:
    IntCounter();
    IntCounter(int* _number);
    IntCounter(const IntCounter& other);
    IntCounter operator=(const IntCounter& other);
    ~IntCounter();

    void setNumber(int* _number);
    int* getNumber() const;

    void setCounter(int _counter);
    int getCounter() const;

    void setPCounter(int* _counter);
    int* getPCounter() const;

    int get_number() const;
    int get_count() const;
};

#endif // INTCOUNTER_H_INCLUDED
