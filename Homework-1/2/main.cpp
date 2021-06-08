#include <iostream>

#include "intCounter.h"

using namespace std;

int main()
{
	int* some_number = new int(5);
    IntCounter first(some_number);
    std::cout << first.get_count() << std::endl;
    //std::cout << "The value of the variable: " << first.get_number() << std::endl;
    IntCounter second = first;
    std::cout << first.get_count() << std::endl;
    //std::cout << "The value of the variable: " << second.get_number() << std::endl;
    {
        IntCounter third(second);
        std::cout << first.get_count() << std::endl;
        //std::cout << "The value of the variable: " << third.get_number() << std::endl;
    }
    std::cout << first.get_count() << std::endl;

//    int* some_number = new int(5);
//    IntCounter first(some_number);
//    IntCounter copyOfFirst(first);
//    std::cout << "The value of the variable: " << first.get_number() << std::endl;
//    std::cout << "The value of the variable: " << copyOfFirst.get_number() << std::endl;
//
//    int* some_other_number = new int(7);
//    IntCounter second(some_other_number);
//    std::cout << "The value of the variable: " << second.get_number() << std::endl;
//
//    std::cout << first.get_count() << std::endl;
//    std::cout << second.get_count() << std::endl;

	return 0;
}
