// <sstream> stringstream
// stringstream allows for you to interact with numbers as if they were input/output streams

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{

    // From the book
    /*
    stringstream ss;
    ss << 3.1415;
    string s = ss.str();
    */
    
    // From https://cplusplus.com/reference/sstream/stringstream/stringstream/
    stringstream ss;
    ss << 100 << ' ' << 200;

    int foo, bar;
    ss >> foo >> bar;

    cout << "foo: " << foo << '\n';
    cout << "bar: " << bar << '\n';

    return 0;
}