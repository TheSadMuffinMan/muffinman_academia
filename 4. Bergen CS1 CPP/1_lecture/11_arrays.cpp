/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
*/

#include <iostream>
#include <string>

using namespace std;

void printArray(int[], size_t);

template <class T1>
void bubbleSort(T1[], size_t);
//                 char **argv
int main(int argc, char *argv[]) {
    // size_t arrSize1, arrSize2, arrSize3;
    // arrSize1 = 5;
    // arrSize2 = 10;
    // arrSize3 = 5;

    // int nums[arrSize1][arrSize2][arrSize3];
    size_t arrSize = 5;

    cout << "How many numbers do you want? ";
    cin >> arrSize;

    int nums[arrSize];

    // nums[0] = 42;
    // nums[1] = 15;
    // nums[2] = 23;
    // nums[3] = 9000;
    // nums[4] = -15;
    for (int i = 0; i < arrSize; i++) {
        cout << "Please enter a whole number: ";
        cin >> nums[i];
    }

    cout << "Start:\t";
    printArray(nums, arrSize);

    bubbleSort<int>(nums, arrSize);

    cout << "End:\t";
    printArray(nums, arrSize);

    return 0;
}

template <class T1>
void bubbleSort(T1 nums[], size_t arrSize) {
    // int numIterations = 0;
    for(size_t j = 0; j < arrSize; j++) {
        // numIterations = 0;
        bool swapped = false;
        for(size_t i = 0; i < arrSize-1-j; i++) {
            if(nums[i] >= nums[i+1]) {
                swapped = true;
                //swap values
                T1 tmpNum = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = tmpNum;
            }
            // numIterations++;
        }
        // cout << "We did " << numIterations << " iterations." << endl;
        // if we are done, break
        if(!swapped) {
            break;
        }

        // cout << j+1 << ":\t";
        // printArray(nums, arrSize);
    }
}

void printArray<float>(int numbers[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        // cout << "numbers[" << i << "]: " << numbers[i] << endl;
        cout << numbers[i] << " ";
    }
    cout << endl;
}


/*
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
*/

/*
    // This is how to create an array on the heap.
    string *myWords; // Can also be string *myWords = new string[x];
    myWords = new string[10];
    delete[] myWords;
*/

    /*
    This is just fun with argument counters and argv stuff...

    cout << "argc: " << argc << endl;
    for (int i=0; i<argc; i++) {
        cout << "argv[" << i << << "]: " << argv[i] << endl;
    }

    if ((string)argv[1] == "test" && argc >= 2) {
        cout << "We are running tests." << endl;
    }
    */

    // long largeNums[100];
    // cout << "The size of largeNums is: " << sizeof(largeNums) << endl;

    // cout << "Press enter to quit: ";
    // cin.get();

    /*
    size_t arrSize = 10;
    getArraySize(arrSize);
    char nums[arrSize];

    cout << "The size of nums is: " << sizeof(nums) << endl;

    populateArray(nums, arrSize);

    for (int i = 0; i < arrSize; i++) {
    cout << "nums[" << i << "]: " << nums[i] << endl;
    }
    */

    /*
    An Array is a dedicated section of memory
    This will create an array named nums, made up of 5 ints, and any empty spaces will be a 0.
    Remember, we always start at 0. 
    You can go past the end of the array without the compiler complaining, but you might be replacing
    something important in that memory address. Called undefined behavior, and C++ will let you go beyond the end of the array.
    The number inside the [] must always be a positive int.
    The first address will always be the same as the actual address as the entire array.
    */
    // int nums[5] = {0};

    /* This will replace all values inside the array with -1.
     unsigned int arrSize = 5;
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