// https://open.kattis.com/problems/keysphonewallet
/*
6/28/24 COMPLETE, very first compilation worked :D

INPUT:
    The first line of input contains a single integer N(1 <= N <= 20) indicating the number of items you
        grabbed before heading out the door. The next N lines each contain a single nonempty string of
        lowercase letters with length at most 10 indicating an item you grabbed before heading out the
        door. No two strings will be the same.

OUTPUT:
    Output each of keys, phone, and wallet that does not appear in the input, one per line and in alphabetic
        order. If you did not forget any of these items, simply print a single line with the text "ready".
*/

#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
    std::size_t numItems = 0;
    std::string comparisonString = " ";
    bool hasKeys = false; bool hasPhone = false; bool hasWallet = false;

    std::cin >> numItems;

    for (std::size_t i = 0; i < numItems; i++)
    {
        std::cin >> comparisonString;
        if (comparisonString == "keys")
        {
            hasKeys = true;
        }
        else if (comparisonString == "phone")
        {
            hasPhone = true;
        }
        else if (comparisonString == "wallet")
        {
            hasWallet = true;
        }
        else {continue;}
    }

    if ((hasKeys == true) && (hasPhone == true) && (hasWallet == true))
    {
        std::cout << "ready";
        return 0;
    }

    if (hasKeys == false)
    {
        std::cout << "keys" << std::endl;
    }

    if (hasPhone == false)
    {
        std::cout << "phone" << std::endl;
    }

    if (hasWallet == false)
    {
        std::cout << "wallet" << std::endl;
    }

    return 0;
}