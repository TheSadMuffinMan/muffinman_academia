/*
Calculates the area of a triangle
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    float n1, n2;
    float answer = 0;
    cin >> n1 >> n2;
    
    answer = ((n1 * n2) / 2);
    cout << answer << endl;

    return 0;
}