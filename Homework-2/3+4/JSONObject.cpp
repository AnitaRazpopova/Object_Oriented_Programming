#include "JsonObject.h"
#include <cstring>
#include <iostream>

const int PUNCTUATIONS = 7;

using namespace std;

JSONObject::JSONObject(){
    key = new char[1];
    key[0] = '\0';
    value = new char[1];
    value[0] = '\0';
    objToString = new char[1];
    objToString[0] = '\0';
}

JSONObject::JSONObject(const char* _key, const char* _value){
    this->setKey(_key);
    this->setValue(_value);
    this->setObjToString();
}

JSONObject::JSONObject(const JSONObject& other){
    this->setKey(other.getKey());
    this->setValue(other.getValue());
    this->setObjToString();
}

JSONObject& JSONObject::operator=(const JSONObject& other){
    if(this == &other){
        return *this;
    }
    this->setKey(other.getKey());
    this->setValue(other.getValue());
    this->setObjToString();
    return *this;
}

JSONObject::~JSONObject(){
    delete[] this->key;
    delete[] this->value;
    delete[] this->objToString;
}

void JSONObject::setKey(const char* _key){
//    delete[] this->key; does not return anything in the console
    this->key = new char[strlen(_key) + 1];
    strcpy(this->key, _key);
}

const char* JSONObject::getKey() const{
    return this->key;
}

void JSONObject::setValue(const char* _value){
//    delete[] this->value; makes the same problem as the one in setKey
    this-> value = new char[strlen(_value) + 1];
    strcpy(this->value, _value);
}

const char* JSONObject::getValue() const{
    return this->value;
}

bool JSONObject::operator==(const JSONObject& other){
    return (strcmp(this->key, other.getKey()) == 0 &&
            strcmp(this->value, other.getValue()) == 0 &&
            strcmp(this->objToString, other.objToString));
}

 void JSONObject::setObjToString(){
    int keySize = strlen(this->key);
    int valueSize = strlen(this->value);
    int sizeObj = keySize + valueSize + PUNCTUATIONS;
    this->objToString = new char[sizeObj + 1];
    int index = 0;
    objToString[index++] = '{';
    objToString[index++] = '"';
    for(int i = 0; i < keySize; i++){
        objToString[index++] = this->key[i];
    }
    objToString[index++] = '"';
    objToString[index++] = ':';
    objToString[index++] = '"';
    for(int i = 0; i < valueSize; i++){
        objToString[index++] = this->value[i];
    }
    objToString[index++] = '"';
    objToString[index++] = '}';
    objToString[index++] = '\0';
 }

const char* JSONObject::getObjToString() const{
    return this->objToString;
}

void JSONObject::printInfo() const{
    cout << "{\"" << this->key << "\": \"" << this->value << "\"}";
}
