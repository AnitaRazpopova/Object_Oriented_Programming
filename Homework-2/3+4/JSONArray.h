#ifndef JSONARRAY_H_INCLUDED
#define JSONARRAY_H_INCLUDED
#include "JsonObject.h"
#include <fstream>

class JSONArray{
private:
    char* arrayName;
    JSONObject* objects;
    int numOfAddedObjects;
    char* arrayToString;
    void setArrayToString();
public:
    JSONArray() ;

    JSONArray(const char* arrayName, JSONObject* _objects, int _numOfAddedObjects);

    JSONArray(const JSONArray& other);

    JSONArray operator=(const JSONArray& other);

    ~JSONArray();

    void setArrayName(const char* _arrayName);

    const char* getArrayName() const;

    void setObjects(const JSONObject* _objects);

    JSONObject* getObjects() const;

    void setNumOfAddedObjects(int _numOdAddedObjects);

    int getNumOfAddedObjects() const;

    bool alreadyAddedObject(const JSONObject& object) const;

    void addObject(const JSONObject& object);

    void removeObject(const char* _key);

    const char* returnValue(const char* _key) ;

    const char* getArrayToString() const;

    void print() const;

    void writeToFile();
};


#endif // JSONARRAY_H_INCLUDED
