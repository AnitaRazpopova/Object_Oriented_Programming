#include "MainFolder.h"
#include <iostream>
#include <cstring>

MainFolder::MainFolder() {
	this->name = nullptr;
	this->dateOfCreation = nullptr;
}
MainFolder::MainFolder(const char* _name, const char* _dateOfCreation) {
	this->setName(_name);
	this->setDateOfCreation(_dateOfCreation);
}
MainFolder::MainFolder(const MainFolder& other) {
	this->setName(other.getName());
	this->setDateOfCreation(other.getDateOfCreation());
}
MainFolder& MainFolder::operator=(const MainFolder& other) {
	if (this == &other) {
		return *this;
	}
	delete[] this->name;
	delete[] this->dateOfCreation;
	this->setName(other.getName());
	this->setDateOfCreation(other.getDateOfCreation());
	return *this;
}
MainFolder::~MainFolder() {
	delete[] this->name;
	delete[] this->dateOfCreation;
}

void MainFolder::setName(const char* _name) {
	//    delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

const char* MainFolder::getName()const {
	return this->name;
}

void MainFolder::setDateOfCreation(const char* _date) {
//	delete[] this->dateOfCreation;
	this->dateOfCreation = new char[strlen(_date) + 1];
	strcpy(this->dateOfCreation, _date);
}

const char* MainFolder::getDateOfCreation()const {
	return this->dateOfCreation;
}
