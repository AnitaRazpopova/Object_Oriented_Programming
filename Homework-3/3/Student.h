#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <vector>
#include <string>
#include "Course.h"
using namespace std;

class Student{
private:
    string nameOfStudent;
    unsigned int facultyNumber;
    vector<Course*> signedCourses;
    vector<double> assessments;
public:
    Student();
    Student(const string& name,unsigned int FN, const vector<Course*> courses, const vector<double> _assessments);
    Student(const Student& other);
    operator=(const Student& other);
    ~Student();
    void addCourse(const Course& other);
    void addAssessments(double other);
    void removeCourse(const Course& other);
    void removeStudent(const Student& other);
    void clearLecturer();
    void clearStudent();
};



#endif // STUDENT_H_INCLUDED
