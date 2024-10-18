/* <typeinfo> library

The Type Info Library allows you to see what type of variable you are dealing with. This is especially useful
    when using streams and validating variable types.

Syntax is a little wonky, but workable:
    std::cout << typeid(variable).name() << std::endl;
*/

#include <iostream>
#include <typeinfo>

int main(int argc, char *argv[])
{
    bool bool1 = false;
    int int1 = 0;
    int intArray[1]; {intArray[0] = 0;}
    char char1 = '0';
    float float1 = 6.9; // Nice.
    double double1 = 42.4242;

    std::string string1 = "string";
    std::string* stringPointer = &string1;

    std::cout << std::endl << typeid(bool1).name() << " == Boolean" << std::endl;
    std::cout << typeid(int1).name() << " == Integer" << std::endl;
    std::cout << typeid(intArray).name() << " == Integer Array" << std::endl;
    std::cout << typeid(char1).name() << " == Char" << std::endl;
    std::cout << typeid(float1).name() << " == Float" << std::endl;
    std::cout << typeid(double1).name() << " == Double" << std::endl;

    std::cout << "\nString: " << typeid(string1).name() << std::endl;
    std::cout << "String Pointer: " << typeid(stringPointer).name() << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}