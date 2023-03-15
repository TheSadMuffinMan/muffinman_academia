/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
*/

#include <iostream>
#include <string>

using namespace std;

void userInput(string&);
void greetUser(string userName);

void getArraySize(size_t&);
void populateArray(char[], size_t);

int main(int argc, char *argv[]) {
    // string userName;
    // userInput(userName);
    // greetUser(userName);
    size_t arrSize = 10;
    getArraySize(arrSize);
    char nums[arrSize];

    cout << "The size of nums is: " << sizeof(nums) << endl;

    populateArray(nums, arrSize);

    for (int i = 0; i < arrSize; i++) {
    cout << "nums[" << i << "]: " << nums[i] << endl;
    }

    /*
    An Array is a dedicated section of memory
    This will create an array named nums, made up of 5 ints, and any empty spaces will be a 0.
    Remember, we always start at 0. 
    You can go past the end of the array without the compiler complaining, but you might be replacing
    something important in that memory address. 
    The number inside the [] must always be an int.
    The first address will always be the same as the actual address as the entire array
    */
    // int nums[5] = {0};

    // This will replace all values inside the array with -1.
    /* unsigned int arrSize = 5;
    int nums[arrSize];
    for (int 1 = 0; i < arrSize; i++) {
        nums[i] = -1;
    }
    */

    /*
    This is the manual way of printing out an array
    nums[0] = 42;
    nums[1] = 15;
    nums[2] = 72;
    nums[3] = 9000;
    nums[4] = -72;
    */

   /*
    // Instead of manually printing out each variable in the array, you can have a for loop to print everything out.
    for (int i=0; i <5; i++) {
        cout << "nums[" << i << "]: " << nums[i] << endl;
    }

    cout << "nums[0]: " << nums[0] << endl;
    cout << "nums[1]: " << nums[1] << endl;
    cout << "nums[2]: " << nums[2] << endl;
    cout << "nums[3]: " << nums[3] << endl;
    cout << "nums[4]: " << nums[4] << endl;
    */

    return 0;
}

void getArraySize(size_t& arrSize) {
    cout << "Please enter how many elements you want in your array: ";
    cin >> arrSize;
}

void populateArray(char characters[], size_t arrSize) {
    for(int i = 0; i < arrSize; i++) {
        cout << "Please enter a character: ";
        cin >> characters[i];
    }
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    // Choose between the two
    // printf("Welcome %s to our multiplication table printer!\n", userName.c_str());
    cout << "Welcome " << userName << " to my program!\n" << endl;
}