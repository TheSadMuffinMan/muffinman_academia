// Start of Class Inheritance

#include <iostream>

using namespace std;

class Base
{
    public:
        Base();
    

    private:
        int _n1;
        string _name;
};

class Derived : public Base
{
    public:
        Derived();
    
    private:
        string _something;
    
};

int main(int argc, char* argv[])
{
    Derived d1;

    
    
    return 0;
}

Base::Base()
{
    cout << "base constructor" << endl;
    _n1 = 0;
    _name = "";
}

Derived::Derived()
{
    cout << "Derived constructor" << endl;
    _something = "";
}