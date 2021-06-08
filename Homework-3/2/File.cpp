#include <iostream>
#include <cstring>
#include "File.h"
using namespace std;

File::File() : hourOfCreation(0), sizeMB(0) {
	this->extension = nullptr;
}

File::File(const char* _name, int _hour, const char* _dateOfCreation, int _size, const char* _extension)
	: MainFolder(_name, _dateOfCreation)
{
	this->setHour(_hour);
	this->setSizeOfFile(_size);
	this->setExtension(_extension);
}

File::File(const File& other)
	:MainFolder(other) {
	this->setHour(other.getHour());
	this->setSizeOfFile(other.getSizeOfFile());
	this->setExtension(other.getExtension());
}

File& File::operator=(const File& other) {
	if (this == &other) {
		return *this;
	}
	MainFolder::operator=(other);
	delete[] this->extension;
	this->setHour(other.getHour());
	this->setSizeOfFile(other.getSizeOfFile());
	this->setExtension(other.getExtension());
	return *this;
}

File::~File() {
	delete[] this->extension;
}

void File::setHour(int _hour) {
	this->hourOfCreation = _hour;
}

int File::getHour()const {
	return this->hourOfCreation;
}

void File::setSizeOfFile(int _size) {
	this->sizeMB = _size;
}

int File::getSizeOfFile()const {
	return this->sizeMB;
}

void File::setExtension(const char* _extension) {
//	delete[] this->extension;
	this->extension = new char[strlen(_extension) + 1];
	strcpy(this->extension, _extension);
}

const char* File::getExtension()const {
	return this->extension;
}

void File::Print() const {
	cout << "Name of file: " << this->name << ", Hour of creation: " << this->hourOfCreation
		<< ", Date of creation: " << this->getDateOfCreation() << ", Size: " << this->sizeMB
		<< "MB, Extension: " << this->extension << ";";
}
