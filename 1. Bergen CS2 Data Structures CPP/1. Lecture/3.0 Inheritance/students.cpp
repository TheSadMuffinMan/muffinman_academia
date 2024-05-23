#include "students.h"

person::Student::Student(int id, string course)
{
    _id = id;
    _course = course;
    cout << "Creating a Student." << endl;
}

void person::Student::setCourse(string course)
{
    _course = course;
}