#ifndef FOLDER_H_INCLUDED
#define FOLDER_H_INCLUDED

#include "MainFolder.h"
#include "File.h"
#include <vector>
using namespace std;

class Folder : public MainFolder {
public:
	Folder();
	Folder(const char* _name, const char* _dateOfCreation, vector<MainFolder*> _list);
	Folder(const Folder& other);
	Folder& operator=(const Folder& other);
	~Folder();

	void Add(MainFolder& other);
	void Remove(const char* _name);
	void RemoveAll();

	virtual void Print() const override;
private:
	vector<MainFolder*> list;
};


#endif // FOLDER_H_INCLUDED
