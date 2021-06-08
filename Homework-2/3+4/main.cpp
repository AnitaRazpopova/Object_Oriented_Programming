#include <iostream>
#include "JsonObject.h"
#include "JsonArray.h"

using namespace std;

int main()
{
    JSONObject name("name", "Anita");
    cout << "Print JSON Object" << endl;
    name.printInfo();
    cout << endl;
    cout << "Print with function - getObjToString" << endl;
    cout << name.getObjToString();
    cout << endl;
    JSONObject FN("facultyNumber", "62495");
    JSONObject lastName("lastName", "Razpopova");
    JSONObject numberOfSiblings("numberOfsiblings", "1");

    JSONObject* data = new JSONObject[0];
    JSONArray personalData("personalData", data, 0);
    personalData.writeToFile();
    personalData.addObject(name);
    personalData.addObject(FN);
    personalData.addObject(lastName);
    personalData.addObject(numberOfSiblings);
    cout << endl;

    cout << "Print JSON Array" << endl;
    personalData.print();
    cout << personalData.getArrayToString();
    cout << endl;

    personalData.writeToFile();
    cout << endl;
    cout << "Delete object by key \"lastName\""<< endl;
    personalData.removeObject("lastName");
    cout << endl;

    cout << "Print JSON Array after deleted object \"lastName\"" << endl;
    personalData.print();
    cout << personalData.getArrayToString();
    cout << endl;
    cout << endl;

    cout << "Print value of key \"facultyNumber\" : ";
    cout << personalData.returnValue("facultyNumber") << ";" << endl;
    personalData.writeToFile();
    cout << endl;
    cout << personalData.getArrayToString();

    delete[] data;

    return 0;
}
