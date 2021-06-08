#include <iostream>
#include <cstring>
#include "myString.h"
#include <limits>

using namespace std;

MyString::MyString() {
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char* text) {
    this->setStr(text);
}

MyString::MyString(const MyString& other){
    this->setStr(other.getStr());
}

MyString& MyString::operator=(const MyString& other){
    if(this == &other){
        return *this;
    } else {
        this->setStr(other.getStr());
        return *this;
    }
}

MyString::~MyString() {
    delete[] this->str;
}

void MyString::setStr(const char* text) {
    this->str = new char[strlen(text) + 1];
    strcpy(this->str, text);
}

char* MyString::getStr() const {
    return this->str;
}

void MyString::print() const {
    cout << this->str << endl;
}

void MyString::append(const char ch) const {
    MyString newStr;
    size_t length = strlen(this->str);
	newStr.str = new char[length + 1];

	for (unsigned int i = 0; i < length; i++) {
		newStr.str[i] = this->str[i];
	}

	newStr.str[length] = ch;
	newStr.str[length + 1] = '\0';

    strcpy(this->str, newStr.str);
}

bool MyString::operator==(const MyString& other) const {
    size_t length = strlen(this->str);
    size_t lengthOther = strlen(other.str);

	if (length != lengthOther) 	{
		return false;
	}
	else {
		for (unsigned int i = 0; i < length; i++) {
			if (this->str[i] != other.str[i]) {
                return false;
            }
		}
	}

	return true;
}

bool MyString::operator!=(const MyString& other) const {
	if (this->operator==(other)) {
		return false;
	}

	return true;
}

bool MyString::operator>(const MyString& other) const {
    size_t length = strlen(this->str);
    size_t lengthOther = strlen(other.str);
    unsigned int len = 0;
    bool isLower = false;

	if (length < lengthOther) {
		len = length;
	}
	else {
        len = lengthOther;
    }

    for (unsigned int i = 0; i < len; i++) {
        if (this->str[i] > other.str[i]) {
            return true;
        }
        else if (str[i] < other.str[i]) {
            isLower = true;
        }
    }

    if (length > lengthOther && !isLower) {
        return true;
    }

	return false;
}

bool MyString::operator<(const MyString& other) const {
    size_t length = strlen(this->str);
    size_t lengthOther = strlen(other.str);
    unsigned int len = 0;
    bool isLower = true;

	if (length < lengthOther) {
		len = length;
	}
	else {
        len = lengthOther;
    }

    for (unsigned int i = 0; i < len; i++) {
        if (this->str[i] < other.str[i]) {
            return true;
        }
        else if (this->str[i] > other.str[i]) {
            isLower = false;
        }
    }

    if (length < lengthOther && isLower) {
        return true;
    }

	return false;
}

ostream& operator<<(ostream& out, const MyString& _str){
    out << "My string : (";
    out << _str.getStr();
    out << ")" << endl;
    return out;
}

istream& operator>>(istream& in, const MyString& _str){
    in.getline(_str.getStr(), numeric_limits<streamsize>::max());
    return in;
}



