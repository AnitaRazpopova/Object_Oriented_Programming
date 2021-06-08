#ifndef JSONARRAY_H_INCLUDED
#define JSONARRAY_H_INCLUDED

#include "JSONObject.h"
#include <fstream>
#include "JsonBase.h"
#include <vector>

using namespace std;

class JSONArray: public JSONBase{
private:
    vector<JSONBase*> list;
    char* arrayName;
    virtual JSONBase* search(const char* key) override;

public:
    JSONArray() ;
    JSONArray(const char* arrayName, vector<JSONBase*> _list);
    JSONArray(const JSONArray& other);
    JSONArray operator=(const JSONArray& other);
    virtual ~JSONArray()override;

    void setArrayName(const char* _arrayName);
    const char* getArrayName() const;
    const char* returnValue(const char* _key) ;

   	void Add(JSONBase& other);
	void RemoveAll();

    virtual void Print() const override;

    void writeToFile();
};



#endif // JSONARRAY_H_INCLUDED
