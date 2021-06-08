#include "FileSystem.h"
#include <iostream>
#include <cstring>

FileSystem::FileSystem()
{
}
FileSystem::FileSystem(vector<MainFolder*> _list)
{
	this->list = _list;
}
FileSystem::FileSystem(const FileSystem& other)
{
	this->list = other.list;
}
FileSystem& FileSystem::operator=(const FileSystem& other)
{
	if (this != &other)
	{
		list.clear();
		this->list = other.list;
	}
	return *this;
}
FileSystem::~FileSystem()
{
	this->list.clear();
}

void FileSystem::search(const char* _name)
{
	for (unsigned int i = 0; i < this->list.size(); i++)
	{
		if (strcmp(this->list.at(i)->getName(), _name) == 0)
		{
			list.at(i)->Print();
		}
	}
}
