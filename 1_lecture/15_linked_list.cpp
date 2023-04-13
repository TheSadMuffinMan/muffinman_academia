/*
Name: Anthony Streich
Date: 13 March 23
Linked Lists!
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node *next;
};

int main(int argc, char *argv[]) {
    int listSize = 0;
    Node *first = new Node({0,NULL}); // Sets the initial value for your struct

    cout << "How many nodes do you want in your linked list? ";
    cin >> listSize;

    Node *currNode = first;
    for(int i=0; i < listSize; i++) {
        Node *nextNode = new Node();
        currNode->next = nextNode;

        cout << "Enter a number: ";
        cin >> nextNode->data;
        nextNode->next = NULL;

        currNode = nextNode;
    }


/*
    // THIS IS THE TEDIOUS WAY OF DOING THINGS.
    Node * first = new Node();
    Node * second = new Node();
    Node * third = new Node();
    Node * fourth = new Node();

    first->data = 42;
    first->next = second;

    second->data = 15;
    second->next = third;

    third->data = 23;
    third->next = fourth;

    fourth->data = 9000;
    fourth->next = NULL;

    // cout << "first->data: " << first->data << endl; // Could do it the manual way, OR you can print it out with a for loop.
    Node *curNode; //Current Node
    curNode = first;
//               ->next. This will make it the pointer version of itself. See below.
    while(curNode != NULL){ // If you use the pointer, you won't get to the last value. See below.
        cout << "curNode->data: " << curNode->data << endl;
        curNode = curNode->next;
    }
    // cout << "curNode->data: " << curNode->data << endl; // You only need this line if the loop is not incrimenting to the last value.

    delete first;
    delete second;
    delete third;
    delete fourth;
*/
    return 0;
}