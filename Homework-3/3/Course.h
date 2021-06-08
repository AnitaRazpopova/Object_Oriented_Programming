#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include <vector>
#include <string>
#include "Course.h"
#include "Student.h"

using namespace std;

class Course{
private:
    string nameOfCourse;
    string typeOfCourse;
    string codeOfCourses;
    Lecturer lecturersOfCourse;
    vector<Student*> signedStudents;
public:
    Course();
    Course(const string& name, const string& type, const string& code, Lecturer _lecturers, vector<Student*> students);
    Course(const Course& other);
    operator=(const Course& other);
    ~Course();
    void setLecturer(const Lecturer& _lecturer);
    Lecturer getLcturer()const;
    void addStudent(const Student& other);
    void removeLecturer(const Lecturer& other);
    void removeStudent(const Student& other);
    void clearLecturer();
    void clearStudent();

};

#endif // COURSE_H_INCLUDED
