#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "MainFolder.h"

class File : public MainFolder { /// class File is base class for class Image and MusicFile,
protected:
	int hourOfCreation;
	int sizeMB;
	char* extension;
public:
	File();
	File(const char* _name, int _hour, const char* _dateOfCreation, int _size, const char* _extension);
	File(const File& _file);
	File& operator=(const File& _file);
	~File();

	void setHour(int _hour);
	int getHour()const;

	void setSizeOfFile(int _size);
	int     getSizeOfFile()const;

	virtual void setExtension(const char* _extension);
	const char* getExtension()const;

	virtual void Print() const override;
};



#endif // FILE_H_INCLUDED
