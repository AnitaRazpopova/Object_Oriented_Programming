#ifndef MUSICFILE_H_INCLUDED
#define MUSICFILE_H_INCLUDED
#include "File.h"
#include "MainFolder.h"

class MusicFile : public File{
protected:
    char* artist;
    char* title;
    char* fileName;
    int year;
    bool CheckExtension(const char* _extension);
public:
    MusicFile();
    MusicFile(const char* _name, int _hour, const char* _dateOfCreation, int _size, const char* _extension,
              const char* _artist, const char* _title, int _year);
    MusicFile(const MusicFile& other);
    MusicFile& operator=(const MusicFile& other);
    ~MusicFile();

    void setArtist(const char* _artist);
    const char* getArtist()const;

    void setTitle(const char* _title);
    const char* getTitle()const;

    void setFileName();
    const char* getFileName()const;

    void setYear(int _year);
    int getYear()const;

    void setExtension(const char* _extension)override;

    virtual void Print() const override;

};


#endif // MUSICFILE_H_INCLUDED
