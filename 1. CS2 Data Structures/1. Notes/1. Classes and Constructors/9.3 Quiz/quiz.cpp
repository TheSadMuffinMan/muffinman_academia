/*
Objects of the BankAccount class require a name (string) and a social security number (string) be specified (in that order) upon creation.
Declare an object named account, of type BankAccount, using the values "John Smith" and "123-45-6789" as the name and social security number respectively.
*/
// Save point
/*
All it wanted was:
BankAccount account("John Smith", "123-45-6789");
*/


#include <iostream>
using namespace std;

class BankAccount
{
    public:
        string name;
        string securityNumber;

        void getName()
        {
            getline(cin, name);
        }

        void getSecurityNumber()
        {
            getline(cin, securityNumber);
        }

};

int main()
{
    BankAccount account;
    return 0;
}