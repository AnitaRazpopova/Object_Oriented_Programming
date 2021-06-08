#ifndef JSONOBJECT_H_INCLUDED
#define JSONOBJECT_H_INCLUDED
class JSONObject{
private:
    char* key;
    char* value;
    char* objToString;
    void setObjToString();

public:
    JSONObject();

    JSONObject(const char* _key, const char* _value);

    JSONObject(const JSONObject& other);

    JSONObject& operator=(const JSONObject& other);

    ~JSONObject();

    void setKey(const char* _key);

    const char* getKey() const;

    void setValue(const char* value);

    const char* getValue() const;

    bool operator==(const JSONObject& other);

    const char* getObjToString() const;

    void printInfo() const;
};




#endif // JSONOBJECT_H_INCLUDED
