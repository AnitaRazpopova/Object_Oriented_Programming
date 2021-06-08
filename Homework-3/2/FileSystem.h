#ifndef FILESYSTEM_H_INCLUDED
#define FILESYSTEM_H_INCLUDED
#include "MainFolder.h"
#include "File.h"
#include "Folder.h"
#include <vector>

class FileSystem{
private:
    vector<MainFolder*> list;

public:
	FileSystem();
	FileSystem(vector<MainFolder*> _list);
	FileSystem(const FileSystem& other);
	FileSystem& operator=(const FileSystem& other);
	~FileSystem();

	void search(const char* _name);

};


#endif // FILESYSTEM_H_INCLUDED
