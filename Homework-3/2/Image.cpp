#include "Image.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

Image::Image() {
	this->nameOfDevice = nullptr;
	this->width = nullptr;
	this->height = nullptr;
	this->resolution = nullptr;
}

Image::Image(const char* _name, int _hour, const char* _dateOfCreation, int _size, const char* _extension,
	const char* _nameOfDevice, const char* _width, const char* _height)
	:File(_name, _hour, _dateOfCreation, _size, _extension) {
	this->setNameOfDevice(_nameOfDevice);
	this->setWidth(_width);
	this->setHeight(_height);
	this->setResolution();
	this->setExtension(_extension);
}
Image::Image(const Image& other) :File(other) {
	this->setNameOfDevice(other.getNameOfDevice());
	this->setWidth(other.getWidth());
	this->setHeight(other.getHeight());
	this->setExtension(other.getExtension());
}
Image& Image::operator=(const Image& other) {
	if (this == &other) {
		return *this;
	}
	File::operator=(other);
	delete[] this->nameOfDevice;
	delete[] this->width;
	delete[] this->height;
	delete[] this->resolution;
	this->setNameOfDevice(other.getNameOfDevice());
	this->setWidth(other.getWidth());
	this->setHeight(other.getHeight());
	this->setExtension(other.getExtension());
	return *this;
}
Image::~Image() {
	delete[] this->nameOfDevice;
	delete[] this->width;
	delete[] this->height;
	delete[] this->resolution;
}

void Image::setNameOfDevice(const char* _nameOfDevice) {
//	delete[] this->nameOfDevice;
	this->nameOfDevice = new char[strlen(_nameOfDevice) + 1];
	strcpy(this->nameOfDevice, _nameOfDevice);
}
const char* Image::getNameOfDevice()const {
	return this->nameOfDevice;
}

void Image::setWidth(const char* _width) {
//	delete[] this->width;
	this->width = new char[strlen(_width) + 1];
	strcpy(this->width, _width);
}
const char* Image::getWidth()const {
	return this->width;
}

void Image::setHeight(const char* _height) {
//	delete[] this->height;
	this->height = new char[strlen(_height) + 1];
	strcpy(this->height, _height);
}
const char* Image::getHeight()const {
	return this->height;
}

void Image::setResolution() {
//	delete[] this->resolution;
	int widthLen = strlen(this->width);
	int heightLen = strlen(this->height);
	int index = 0;
	this->resolution = new char[widthLen + heightLen + 2];
	for (int i = 0; i < widthLen; i++) {
		this->resolution[index++] = this->width[i];
	}
	resolution[index++] = '/';
	for (int i = 0; i < heightLen; i++) {
		this->resolution[index++] = this->height[i];
	}
	this->resolution[index++] = '\0';
}
const char* Image::getResolution()const {
	return this->resolution;
}

bool Image::CheckExtension(const char* _extension) {
	if (strcmp(_extension, ".png") == 0 || strcmp(_extension, ".jpg") == 0) {
		return true;
	}
	return false;
}

void Image::setExtension(const char* _extension) {
	if (CheckExtension(_extension) == true) {
		File::setExtension(_extension);
	}
	else
	{
		cout << "Invalid extension";
//		delete[] this->extension;
		this->extension = new char[1];
		this->extension[0] = '\0';
	}

}


void Image::Print() const {
	File::Print();
	cout << " Name of device that took the picture: " << this->nameOfDevice
		<< ", Resolution: " << this->resolution << "- width/height;" << endl;
}
