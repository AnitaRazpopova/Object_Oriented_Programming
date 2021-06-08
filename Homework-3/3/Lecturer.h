#ifndef LECTURER_H_INCLUDED
#define LECTURER_H_INCLUDED
#include <vector>
#include <string>
#include "Course.h"
using namespace std;

enum Designation{part_timer, principal_assistant, doctor, docent, professor};

class Lecturer{
private:
    string nameOfLecturer;
    Designation designation;
    vector<Course*> leadingCourses;
public:
    Lecturer();
    Lecturer(const string& name, Designation _designation, vector<Course*> courses);
    Lecturer(const Lecturer& other);
    operator=(const Lecturer& other);
    ~Lecturer();
    void setDesignation(Designation _designation);
    Designation getDesignation() const;
    void addCourse(const Course& other);
    void removeCourse(const Course& other);

};

#endif // LECTURER_H_INCLUDED
