/* Stuff and things

*/


// Void statement

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// // TEMPLATES
// template <class T1, class T2> // These are generic types
// T1 addNums(T1 num1, T2 num2) {
//     T1 answer;
//     answer = num1 + num2;
//     return num1 + num2;
// }

// int addNums(int num1, int num2) {
//     return num1 + num2;

// }

// float addNums(float num1, float num2) {
//     return num1 + num2 + 10;

// }

// int addNums(float num1, int num2) {
//     return num1 + num2 + 10;

// }

void say_goodbye();
void say_hello();
int addNums(int, int);


int main() {
    say_hello();


    return 0;

}
// People usually put their functions at the bottom of their code, so long as they are defined before main().
void say_goodbye() {
    cout << "Goodbye everyone" << endl;
    say_hello();
}

int addNums(int num1, int num2) {
    return num1 + num2;
}

void say_hello() {
    cout << "Hello world" << endl;
    say_goodbye();
}