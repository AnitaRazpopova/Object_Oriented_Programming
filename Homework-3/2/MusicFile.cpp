#include "MusicFile.h"
#include <iostream>
#include <cstring>
using namespace std;

const int PUNCTUATION = 7;

MusicFile::MusicFile():year(0){
    this->artist = nullptr;
    this->title = nullptr;
    this->fileName = nullptr;
}

MusicFile::MusicFile(const char* _name, int _hour, const char* _dateOfCreation, int _size, const char* _extension,
              const char* _artist, const char* _title, int _year)
          :File(_name, _hour, _dateOfCreation, _size, _extension){
          this->setArtist(_artist);
          this->setTitle(_title);
          this->setFileName();
//          this->setMusicExtension(_extension);
          this->setYear(_year);
}

MusicFile::MusicFile(const MusicFile& other): File(other){
    this->setArtist(other.getArtist());
    this->setTitle(other.getTitle());
    this->setYear(other.getYear());
//    this->setMusicExtension(other.getMusicExtension());
}

MusicFile& MusicFile::operator=(const MusicFile& other){
    if(this == &other){
        return *this;
    }
    File::operator=(other);
    delete[] this->artist;
    delete[] this->title;
    delete[] this->fileName;
    this->setArtist(other.getArtist());
    this->setTitle(other.getTitle());
    this->setYear(other.getYear());
//    this->setMusicExtension(other.getMusicExtension());
    return *this;
}

MusicFile::~MusicFile(){
    delete[] this->artist;
    delete[] this->title;
    delete[] this->fileName;
}

void MusicFile::setArtist(const char* _artist){
 //   delete[] this->artist;
    this->artist = new char [strlen(_artist) + 1];
    strcpy(this->artist, _artist);
}
const char* MusicFile::getArtist()const{
    return this->artist;
}

void MusicFile::setTitle(const char* _title){
 //   delete[] this->title;
    this->title = new char[strlen(_title) + 1];
    strcpy(this->title, _title);
}
const char* MusicFile::getTitle()const{
    return this->title;
}

void MusicFile::setFileName(){
//    delete[] this->fileName;
    int artistLen = strlen(this->artist);
    int titleLen = strlen(this->title);
    int index = 0;
    this->fileName = new char[artistLen + titleLen + PUNCTUATION + 1];
    this->fileName[index++] = '`';
    this->fileName[index++] = '<';
    for(int i = 0; i < artistLen; i++){
        if(artist[i] ==' '){
            this->fileName[index++] = '-';
            this->fileName[index++] = this->artist[++i];
        }else {
            this->fileName[index++] = this->artist[i];
        }
    }
    this->fileName[index++] = '>';
    this->fileName[index++] = ' ';
    this->fileName[index++] = '-';
    this->fileName[index++] = ' ';
    this->fileName[index++] = '<';
    for(int i = 0; i < titleLen; i++){
        if(title[i] ==' '){
            this->fileName[index++] = '-';
            this->fileName[index++] = this->title[++i];
        }else {
            this->fileName[index++] = this->title[i];
        }
    }
    this->fileName[index++] = '>';
    this->fileName[index++] = '`';
    this->fileName[index++] = '\0';
}
const char* MusicFile::getFileName()const{
    return this->fileName;
}

void MusicFile::setYear(int _year){
    this->year = _year;
}
int MusicFile::getYear()const{
    return this->year;
}
bool MusicFile::CheckExtension(const char* _extension){
    if(strcmp(_extension, ".mp3") == 0 || strcmp(_extension, ".flac") == 0){
        return true;
    }
    return false;
}
void MusicFile::setExtension(const char* _extension){
    if(CheckExtension(_extension)== true){
        File::setExtension(_extension);
    }
    cout << "Invalid Extension" << endl;
}

void MusicFile::Print() const {
    File::Print();
//    cout << "Artist: " << this->getArtist() << ", Title:  \" " << this->getTitle() << "\" , File extension:"
    cout << " File name: " << this->getFileName() << "; " << endl;
}
