/* Test input:
3.14
2.71
2.5
42

g++ -o main main.cpp
*/

#include <iostream>
#include <string>

void round_number(std::string& passed_string)
{
    std::size_t dot = passed_string.find('.');

    // Ideal case: already an int.
    if (dot == std::string::npos)
        return;

    bool round_up = ((dot + 1 < passed_string.size()) && (passed_string[dot + 1] >= '5'));

    // Removing decimal portion.
    passed_string.erase(dot);

    if (!round_up)
        return;

    // Rounding up integer.
    int i = (passed_string.size() - 1);
    while (i >= 0 && (passed_string[i] == '9')) {
        passed_string[i] = '0';
        --i;
    }

    if (i >= 0) {
        passed_string[i]++;
    } else {
        // Overflow/Edge case (99.6 -> 100).
        passed_string.insert(0, "1");
    }
}

int main(int argc, char* argv[])
{
    std::string user_string;
    std::cin >> user_string;
    round_number(user_string);
    std::cout << user_string;

    // std::cout << "\nEnd of program.\n";
    return 0;
}