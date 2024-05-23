#pragma once

#include "person.h"

namespace person
{
    class Student : public Person
    {
        public:
            Student(int = 0, string = "");
            void setCourse(string);
        
        private:
            int _id;
            string _course;
    };
}