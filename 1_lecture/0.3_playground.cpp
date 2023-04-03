// PLAYGROUND

#include <iostream>
#include <cstdlib> // for rand() and srand() 
#include <ctime> // for time() 
using namespace std; 

 int main () { 

   // Initialize the random number generator 
   // srand(time(0)); 

   // Generate a random number between 1 and 20       
   int r = (rand() % 20) + 1; 

   cout << "Random number: " << r << endl;

    return 0;    }