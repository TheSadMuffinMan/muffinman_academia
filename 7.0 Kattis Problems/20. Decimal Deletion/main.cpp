/* Test input:
3.14
2.71
2.5
42
*/

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        char *curr = argv[i];  // Current argument; program name is at argv[0].

        // C-Strings end at the first `\0`...
        while (*curr != '\0')
        {
            if (*curr == '.')
            {
                *curr = '\0'; // Truncate at decimal.
                break;
            }

            if (!std::isdigit(*curr))
            {
                std::cerr << "Invalid character: " << *curr << '.\n';
                return 1;
            }

            ++curr;
        }

        std::cout << "Cleaned arg: " << argv[i] << '\n';
    }

    std::cout << "\nEnd of program.\n";
    return 0;
}