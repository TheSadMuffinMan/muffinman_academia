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