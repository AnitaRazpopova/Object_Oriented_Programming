#include "JsonArray.h"
#include <cstring>
#include <iostream>

const int PUNCTUATIONS = 12;

using namespace std;

JSONArray::JSONArray() : objects(nullptr), numOfAddedObjects(0) {
    arrayName = new char[1];
    arrayName[0] = '\0';
    arrayToString = new char[1];
    arrayToString[0] = '\0';
};

JSONArray::JSONArray(const char* _arrayName, JSONObject* _objects, int _numOfAddedObjects):
    objects(_objects),
    numOfAddedObjects(_numOfAddedObjects){
        this->setArrayName(_arrayName);
        this->setArrayToString();
        this->getArrayToString();
    }

JSONArray::JSONArray(const JSONArray& other){
    this->setArrayName(other.getArrayName());
    this->setObjects(other.getObjects());
    this->setNumOfAddedObjects(other.getNumOfAddedObjects());
    this->setArrayToString();
}

JSONArray JSONArray::operator=(const JSONArray& other){
    if(this == &other){
        return *this;
    }
    this->setArrayName(other.getArrayName());
    this->setObjects(other.getObjects());
    this->setNumOfAddedObjects(other.getNumOfAddedObjects());
    this->setArrayToString();
    return *this;

}

JSONArray::~JSONArray(){
    delete[] this->arrayName;
    delete[] this->objects;
    delete[] this->arrayToString;
}

void JSONArray::setArrayName(const char* _arrayName){
 //   delete[] this->arrayName; makes problems from time to time when i try to compile(no error warning)
    this->arrayName = new char[strlen(_arrayName) + 1];
    strcpy(this->arrayName, _arrayName);
}

const char* JSONArray::getArrayName() const{
    return this->arrayName;
}

void JSONArray::setObjects(const JSONObject* _objects){
    delete[] objects;
    this->objects = new JSONObject[this->numOfAddedObjects + 1];
    for(int i = 0; i < this->numOfAddedObjects; i++){
        objects[i] = _objects[i];
    }
}

JSONObject* JSONArray::getObjects() const{
    return this->objects;
}

void JSONArray::setNumOfAddedObjects(int _numOfAddedObjects){
    this->numOfAddedObjects = _numOfAddedObjects;
}

int JSONArray::getNumOfAddedObjects() const{
    return this->numOfAddedObjects;
}

void JSONArray::setArrayToString(){
    int nameLen = strlen(this->arrayName);
    int punctuationBetweenObjects = this->numOfAddedObjects * 4;
    int arrayLen = nameLen + PUNCTUATIONS + punctuationBetweenObjects;;
    int objLen = 0;
    int index = 0;
    for(int i = 0; i < this->numOfAddedObjects; i++){
        objLen = strlen(objects[i].getObjToString());
        arrayLen = arrayLen + objLen;

    }
    delete[] arrayToString;
    this->arrayToString = new char[arrayLen + 1];
    arrayToString[index++] = '{';
    arrayToString[index++] = '\n';
    arrayToString[index++] = '\t';
    arrayToString[index++] = '"';
    for(int i = 0; i < nameLen; i++){
        arrayToString[index++] = arrayName[i];
    }
    arrayToString[index++] = '"';
    arrayToString[index++] = ':';
    arrayToString[index++] = '[';
    for (int i = 0; i < this->numOfAddedObjects; i++){
        arrayToString[index++] = '\n';
        arrayToString[index++] = '\t';
        arrayToString[index++] = '\t';
        int len = strlen(objects[i].getObjToString());
        for(int j = 0; j < len; j++){
            arrayToString[index++] = objects[i].getObjToString()[j];
        }
        if(i < (this->numOfAddedObjects - 1)){
            arrayToString[index++] = ',';
        }
    }
    arrayToString[index++] = '\n';
    arrayToString[index++] = '\t';
    arrayToString[index++] = ']';
    arrayToString[index++] = '\n';
    arrayToString[index++] = '}';
    arrayToString[index++] = '\0';
}

const char* JSONArray::getArrayToString() const{
    return this->arrayToString;
}

bool JSONArray::alreadyAddedObject(const JSONObject& object)const {
	for (int i = 0;i < this->numOfAddedObjects;i++) {
		if (objects[i] == object) {
			return true;
		}
	}
	return false;
}

void JSONArray::addObject(const JSONObject& object) {
	if (alreadyAddedObject(object) == true) {
		cout << "Already added" << endl;
		return;
	}
	JSONObject* _objects = new JSONObject[this->numOfAddedObjects + 1];
    for(int i = 0; i < this->numOfAddedObjects; i++){
        _objects[i] = objects[i];
    }
    this->numOfAddedObjects++;

    objects = new JSONObject[this->numOfAddedObjects + 1];
    for(int i = 0; i < this->numOfAddedObjects - 1; i++){
        objects[i] = _objects[i];
    }
    objects[this->numOfAddedObjects - 1] = object;
    this->setArrayToString();
    delete[] _objects;
}

void JSONArray::removeObject(const char* _key) {
        int index = 0;
        JSONObject* _objects = new JSONObject[this->numOfAddedObjects];
		for (int i = 0; i < numOfAddedObjects; i++) {
			if (strcmp(objects[i].getKey(), _key) == 0) {
                index++;
				_objects[i] = objects[index];
				this->numOfAddedObjects--;
			} else {
			_objects[i] = objects[index];
			index++;
			}
		}

		objects = new JSONObject[this->numOfAddedObjects];
		for (int i = 0; i < this->numOfAddedObjects; i++) {
			objects[i] = _objects[i];
		}

        this->setArrayToString();

		delete[] _objects;
}

const char* JSONArray::returnValue(const char* _key) {
    for(int i = 0; i < this->numOfAddedObjects; i++){
        if(strcmp(objects[i].getKey(), _key) == 0){
            return objects[i].getValue();
        }
    }
    return "no matching key";
}

void JSONArray::writeToFile() {
    ofstream writeFile("personalData.json", ios::app);
    writeFile << this->arrayToString << endl;
    writeFile.close();
}

void JSONArray::print() const{
    cout << "[ " ;
    for(int i = 0; i < this->numOfAddedObjects ; i++){
        objects[i].printInfo();
        if(i < this->numOfAddedObjects - 1){
            cout << ",";
        }
        cout <<endl;
    }
    cout << "]" << endl;
}
