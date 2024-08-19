#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    vector<int> myNums;
    vector<int> myNums2;

    myNums.push_back(42);
    myNums.push_back(15);
    myNums.push_back(23);
    myNums.push_back(9000);
    myNums.push_back(-15);

    // If you'd like to know the size of your vector, simply add .size() after your vector.
    cout << "myNums.size(): " << myNums.size() << endl;

    // Capacity shows how many elements the vector can hold before needing to add more memory
    // Will be a power of two (because binary)
    cout << "myNums.capacity" << myNums.capacity() << endl;

    // This will return true if the vector is empty.
    cout << "myNums.empty: " << myNums.empty() << endl;

    // This removes the last element. It does NOT display or return the element.
    cout << "myNums.at(myNums.size()-1): " << myNums.at(myNums.size()-1) << endl;
    myNums.pop_back();
    cout << "myNums.size(): " << myNums.size() << endl;

    // Removes an element at the given postition.
    myNums.erase(myNums.end()-1);

    // You can set vectors to equal each other, but you can't with arrays.
    // myNums2 = myNums;

/*
    // This will show you the max amount of elements that you can have in the vector.
    vector<string> myStr;
    cout << myStr.max_size() << endl;
*/

    // These are ways how to print out what is inside your vector.
    for(int i=0; i < myNums.size(); i++) {
        cout << "myNums.at(" << i << "): " << myNums.at(i) << endl;
    }

    for (auto it = myNums.begin(); it != myNums.end(); it++) {
        cout << "*it: " << *it << endl;
        if (*it == 42) { // This will delete all elements with value of 42
            myNums.erase(it);
        }
    }

    // This one will continue to print things until there is nothing left.
    for(int elem: myNums) {
        cout << "elem: " << elem << endl;
    }



    return 0;
}