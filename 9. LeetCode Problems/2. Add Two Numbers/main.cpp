#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    // Constructor:
    ListNode() : val(0), next(nullptr) {};

    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

struct makeListNode {
    //
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
};

int main(int argc, char* argv[]) {
    int input1, input2;
    std::cout << "Please input a non-negative number: ";
    std::cin >> input1;

    std::cout << "Please input another non-negative number: ";
    std::cin >> input2;
    

    std::cout << "\n\nProgram complete." << std::endl;
    return 0;
}