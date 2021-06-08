#include <iostream>
#include "intCounterTemplate.cpp"

using namespace std;

int main()
{
    int* some_number = new int(5);
    IntCounter<int> first(some_number);
    std::cout << first.get_count() << std::endl;
    IntCounter<int> second = first;
    std::cout << first.get_count() << std::endl;

    {
        IntCounter<int> third(second);
        std::cout << first.get_count() << std::endl;
    }
    std::cout << first.get_count() << std::endl;

//    int* some_number = new int(5);
//    IntCounter<int> first(some_number);
//
//    int* some_other_number = new int(7);
//    IntCounter<int> second(some_other_number);
//
//    std::cout << first.get_count() << std::endl;
//    std::cout << second.get_count() << std::endl;

	return 0;
}
