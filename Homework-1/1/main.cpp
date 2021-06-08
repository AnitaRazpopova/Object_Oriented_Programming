#include <iostream>

#include "myString.h"

using namespace std;

int main()
{
    MyString temp("Hello world");
    temp.print();
    temp.append('!');
    temp.print();

    MyString strA("abc");
    MyString strB("abc");

    strA.print();
    strB.print();

    if(strA == strB) {
        cout << "The strings are equals" << endl;
    }
    else {
        cout << "The strings are not equals" << endl;
    }

    if(strA != strB) {
        cout << "The strings are not equals" << endl;
    }
    else {
        cout << "The strings are equals" << endl;
    }

    MyString strC("abc");
    MyString strD("abd");

    strC.print();
    strD.print();

    if(strC == strD) {
        cout << "The strings are equals" << endl;
    }
    else {
        cout << "The strings are not equals" << endl;
    }

    if(strC != strD) {
        cout << "The strings are not equals" << endl;
    }
    else {
        cout << "The strings are equals" << endl;
    }

    MyString strE("abb");
    MyString strF("abc");

    strE.print();
    strF.print();

    if(strE > strF) {
        cout << "The first string are greater than second" << endl;
    }

    if(strE < strF) {
        cout << "The first string are lower than second" << endl;
    }

    return 0;
}
