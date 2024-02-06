// The friend keyword allows functions to access everything inside of your classes.
// This is useful because it allows for your data to be "friendly" with multiple classes.
// This practice is also dangerous because it allows full access to your private data members.

#include <iostream>

using namespace std;

class Rectangle
{
    public:
        Rectangle(int, int);

    private:
        int _side1, _side2;
};

int CalcArea(Rectangle&);

int main(int argc, char *argv[])
{
    Rectangle rect1();
    return 0;
}

Rectangle::Rectangle(int side1, int side2)
{
    _side1 = side1;
    _side2 = side2;
}

int CalcArea(Rectangle& rect1)
{
    //
}
