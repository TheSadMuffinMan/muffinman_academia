// https://www.youtube.com/watch?v=edfATDog-LQ
// Operator Overloading in C++ by Simplilearn

// WORKING :D :D :D 4/30/24

/*
Operator overloading allows a user to utilize standard operators with user specific data.
GENERAL SYNTAX: returnType operator symbol(arguments)

---------------------------------------------------------------------------------------------------------------
OPERATORS THAT CANNOT BE OVERLOADED: (syntactically impossible to overload)
    . (dot operator)
    :: (scope resolution operator)
    .* (pointer to member operator)
    ?: (ternary operator)

---------------------------------------------------------------------------------------------------------------
There are two types of operator overloading: Unary Operator Overloading and Binary Operator Overloading
UNARY OPERATOR OVERLOADING: An operator which only contains one operand. Best examples are ++ and --.
    Syntax:
        returnType operator symbol()

BINARY OPERATOR OVERLOADING: An operator that contains two operands. Much more common.
    Synatx:
        returnType operator symbol(argument)

*/
#include <iostream>

using namespace std;


class UnaryClass
{
    public:
        UnaryClass() {_value = 10;}

        int operator ++() {_value = _value + 5;return _value;} // Prefix notation.
        int operator ++ (int) {_value = (_value + 1);return _value;} // Postfix notation, allows Inc++;

        void display() {cout << "Value is: " << _value << endl;}

    private:
        int _value;

/* ***PASTE IN MAIN***
    UnaryClass Inc;
    ++Inc; // Inc++ also works.
    Inc.display();
*/
};

class BinaryClass
{
    public:
        BinaryClass();
        BinaryClass(int, int);
        int getReal();
        int getImaginary();
        void setReal(int);
        void setImaginary(int);

        friend BinaryClass operator+(const BinaryClass, const BinaryClass); // See implementation for explanation.

        // The goal of this function is to return the address to the ostream.
        // The friend keyword allows access to private data members.
        friend ostream& operator << (ostream& os, const BinaryClass& inputClass) // See "Implementation" for notes.
        {
            os << inputClass._real << " + " << inputClass._imaginary << " ";
            return os;
        }
    
    private:
        int _real;
        int _imaginary;
};

int main(int argc, char *argv[])
{
    int inputReal1, inputImag1, inputReal2, inputImag2;
    cout << "Please enter a complex number seperated by a space: ";
    cin >> inputReal1;
    cin >> inputImag1;

    cout << "\nPlease enter another complex number seperated by a space: ";
    cin >> inputReal2;
    cin >> inputImag2;

    BinaryClass num1(inputReal1, inputImag1);
    BinaryClass num2(inputReal2, inputImag2);

    BinaryClass num3 = num1 + num2;

    cout << "Answer: " << num3 << endl;

    return 0;
}

BinaryClass::BinaryClass()
{
    _real = 0;
    _imaginary = 0;
}

BinaryClass::BinaryClass(int num1, int num2)
{
    _real = num1;
    _imaginary = num2;
}

int BinaryClass::getReal()
{
    return _real;
}

int BinaryClass::getImaginary()
{
    return _imaginary;
}

void BinaryClass::setReal(int data)
{
    _real = data;
}

void BinaryClass::setImaginary(int data)
{
    _imaginary = data;
}


// Function is a "friend" because the function needs to have access to private BinaryClass members.
// Friend also allows this function to be utilized in other classes.
// Normally function arguments need to be dereferenced (const &BinaryTree ...), but because
// we are not using pointers, this is not needed.
BinaryClass operator +(const BinaryClass object1, const BinaryClass object2)
{
    BinaryClass temp;
    int tempReal, tempImag;

    tempReal = object1._real + object2._real;
    tempImag = object1._imaginary + object2._imaginary;

    temp.setReal(tempReal);
    temp.setImaginary(tempImag);

    return temp;
};

/*
This function must be implemented inside of class declaration because we are using namespace std.
Because ostream is a part of the STL, we would have to redefine is outside of the class declaration.
ostream BinaryClass::operator << (ostream& os, const BinaryClass object)
{
    //
} */