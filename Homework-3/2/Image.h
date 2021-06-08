#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include "File.h"
#include "MainFolder.h"

class Image : public File {
protected:
	char* nameOfDevice;
	char* width;
	char* height;
	char* resolution;
	bool CheckExtension(const char* _extension);
public:
	Image();
	Image(const char* _name, int _hour, const char* _dateOfCreation, int _size, const char* _extension,
		const char* _nameOfDevice, const char* _width, const char* _height);
	Image(const Image& other);
	Image& operator=(const Image& other);
	~Image();

	void setNameOfDevice(const char* _nameOfDevice);
	const char* getNameOfDevice()const;

	void setWidth(const char* _width);
	const char* getWidth()const;

	void setHeight(const char* _height);
	const char* getHeight()const;

	bool resolutionValidation();
	void setResolution();
	const char* getResolution()const;

	virtual void setExtension(const char* _extension)override;

	virtual void Print() const override;
};


#endif // IMAGE_H_INCLUDED
