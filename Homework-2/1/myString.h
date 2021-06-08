#ifndef MYSTRING_H
#define MYSTRING_H

using namespace std;
class MyString{

private:
    char* str;

public:

    MyString();

    MyString(const char* text);

    MyString (const MyString& other);

    MyString& operator=(const MyString& other);

    ~MyString();

    void setStr(const char* text);

    char* getStr() const ;

    void print() const;

    void append(char ch) const;

    bool operator==(const MyString &other) const;

    bool operator!=(const MyString &other) const;

    bool operator>(const MyString &other) const;

    bool operator<(const MyString &other) const;

    friend ostream& operator<<(ostream& out, const MyString& _str);

    friend istream& operator>>(istream& in, const MyString& _str);
};

#endif // MYSTRING_H
