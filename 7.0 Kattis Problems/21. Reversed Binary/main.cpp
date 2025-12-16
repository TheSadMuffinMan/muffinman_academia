/* Test input:


g++ -o main main.cpp
*/

#include <iostream>
#include <string>
#include <bitset>

int main(int argc, char* argv[])
{
    int decimalNumber = 42;
    // Specifing the number of bits; we won't need more than 32 to represent < 1 billion.
    std::string binaryString = std::bitset<32>(decimalNumber).to_string();

    std::cout << "Binary representation: " << binaryString << std::endl;
    // Output for 42 might be "00000000000000000000000000101010"
    // One billion in binary:  00111011100110101100101000000000

    // To remove leading zeros, you can find the first '1' and take a substring:
    size_t firstOne = binaryString.find('1');
    if (firstOne != std::string::npos) {
        std::cout << "Binary without leading zeros: " << binaryString.substr(firstOne) << std::endl;
    } else {
        std::cout << "Binary without leading zeros: 0" << std::endl; // Case for input 0
    }

    return 0;
}