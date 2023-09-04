// <string> c_str()
// From https://cplusplus.com/reference/string/string/c_str/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main ()
{
  string str ("Please split this sentence into tokens");

  char * cstr = new char [str.length()+1];
  strcpy (cstr, str.c_str());

  // cstr now contains a c-string copy of str

  char * p = strtok (cstr," ");
  while (p!=0)
  {
    cout << p << '\n';
    p = strtok(NULL," ");
  }

  delete[] cstr;
  return 0;
}