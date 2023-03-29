// PLAYGROUND

#include <iostream>
#include <string>

using namespace std;

void squareStuff(int);

int main(int argc, char *argv[]) {
    int height;
    cout << "Enter height: " << endl;
    cin >> height;

    squareStuff(height);
    return 0;
}

void squareStuff(int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < height; j++){
            cout << "* ";
    }
    cout << endl; // THIS TOOK ME SO FKING LONG TO FIGURE OUT
}
}