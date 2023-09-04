// <string> operators

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string s1 = "ABC"; // The = operator
    string s2 = s1;

    for (unsigned i = s2.size() - 1; i >= 0; i--)
    {
        cout << s2[i]; // The [] operator
    }

    string s3 = s1 + "DEFG"; // The + operator
    cout << s3 << endl; // s3 becomes "ABCDEFG"

    s1 += "ABC";
    cout << s1 << endl; // s1 becomes ABCABC

    s1 = "ABC";
    s2 = "ABE";
    cout << (s1 == s2) << endl; // Displays 0 (false)
    cout << (s1 != s2) << endl; // Displays 1 (true)
    cout << (s1 > s2) << endl; // Displays 0 (false)
    cout << (s1 >= s2) << endl; // Displays 0 (false)
    cout << (s1 < s2) << endl; // Displays 1 (true)
    cout << (s1 <= s2) << endl; // Displays 1 (true)

    return 0;
}