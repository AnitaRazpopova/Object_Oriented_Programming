#ifndef MAINFOLDER_H_INCLUDED
#define MAINFOLDER_H_INCLUDED

class MainFolder { ///class MainFolder would be my base abstract class, children are class File and class Folder
protected:
	char* name;
	char* dateOfCreation;
public:
	MainFolder();
	MainFolder(const char* _name, const char* _dateOfCreation);
	MainFolder(const MainFolder& other);
	MainFolder& operator=(const MainFolder& other);
	~MainFolder();

	void setName(const char* _name);
	const char* getName()const;

	void setDateOfCreation(const char* _date);
	const char* getDateOfCreation()const;

	virtual void Print() const = 0;

};

#endif // MAINFOLDER_H_INCLUDED
