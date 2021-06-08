#ifndef MYSTRING_H
#define MYSTRING_H

class MyString{

private:
    char* str;

public:

    MyString();

    MyString(char* text);

    Mystring (const MyString& other);

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
};

#endif // MYSTRING_H
