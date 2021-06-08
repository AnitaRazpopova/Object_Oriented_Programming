#include "Folder.h"
#include <iostream>
#include <cstring>

Folder::Folder(){}

Folder::Folder(const char* _name,const char* _dateOfCreation, vector<MainFolder*> _list)
	:MainFolder(_name,_dateOfCreation){
	this->list = _list;
}

Folder::Folder(const Folder& other)
	: MainFolder(other){
	this->list = other.list;
}

Folder& Folder::operator=(const Folder& other){
	if (this != &other){
		list.clear();
		MainFolder::operator=(other);
		this->list = other.list;
	}
	return *this;
}

Folder::~Folder(){
	list.clear();
}

void Folder::Add(MainFolder& other){
	list.push_back(&other);
}

void Folder::Remove(const char* _name){
	for (unsigned int i = 0; i < this->list.size(); i++)
	{
		if(strcmp(this->list.at(i)->getName(),_name) == 0)
		{
			this->list.erase(this->list.begin() + i);
		}
	}
}

void Folder::RemoveAll(){
	list.clear();
}

void Folder::Print() const{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		list.at(i)->Print();
		cout << std::endl;
	}
}
