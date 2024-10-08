#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace person
{
    class Person
    {
        public:
            Person(string = "", int = 0, int = 0);

        protected:
            string getName();
        
        private:
            string _name;
            int _age;
            int _height;
    };
}