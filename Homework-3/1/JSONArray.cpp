#include "JSONArray.h"
#include <cstring>
#include <iostream>
#include <algorithm>

const int PUNCTUATIONS = 12;

JSONArray::JSONArray() {
    this->arrayName = nullptr;
}

JSONArray::JSONArray(const char* _arrayName, vector<JSONBase*> _list){
        this->setArrayName(_arrayName);
        this->list = _list;
    }

JSONArray::JSONArray(const JSONArray& other){
    this->setArrayName(other.getArrayName());
    this->list = other.list;
}

JSONArray JSONArray::operator=(const JSONArray& other){
    if(this == &other){
        return *this;
    }
    list.clear();
    this->setArrayName(other.getArrayName());
    this->list = other.list;
    return *this;
}

JSONArray::~JSONArray(){
    delete[] this->arrayName;
    list.clear();
}


void JSONArray::setArrayName(const char* _arrayName){
 //   delete[] this->arrayName; makes problems from time to time when i try to compile(no error warning)
    this->arrayName = new char[strlen(_arrayName) + 1];
    strcpy(this->arrayName, _arrayName);
}

const char* JSONArray::getArrayName() const{
    return this->arrayName;
}

JSONBase* JSONArray::search(const char* key){
    JSONBase* res = nullptr;
    for(unsigned int i = 0; i < this->list.size() && res == nullptr; i++){
        res = this->list[i]->search(key);
    }
    return res;
}

void JSONArray::Add(JSONBase& other){
    list.push_back(&other);
}

void JSONArray::RemoveAll(){
    list.clear();
}

void JSONArray::Print() const{
    cout << "[ "  << endl;
    for(unsigned int i = 0; i < this-> list.size(); i++){
        list.at(i)->Print();
		cout << std::endl;
    }
    cout << "]" << endl;
}
