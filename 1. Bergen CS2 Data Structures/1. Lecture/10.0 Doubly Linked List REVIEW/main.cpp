// TEMPLATED DOUBLY LINKED LIST (with Recusion)
// Lecture from 4/25/24.
// See List<T1>::walkList() for an example of recursion with explanation.

#include <iostream>

using namespace std;

template <typename T1>
class Node
{
    public:
        Node(T1 data, Node<T1>* prev, Node<T1>* next) {_data = data; _prev = prev; _next = next;}
        void setData(T1 data) {_data = data;}
        void setPrev(Node<T1>* prev) {_prev = prev;}
        void setNext(Node<T1>* next) {_next = next;}

        T1 getData() {return _data;}
        Node* getPrev() {return _prev;}
        Node* getNext() {return _next;}

    
    private:
        T1 _data;
        Node<T1>* _prev;
        Node<T1>* _next;
};

template <typename T1>
class List
{
    public:
        void addEnd(T1);
        void addStart(T1);

        T1 getEnd();
        T1 getStart();

        void printList();
    
    private:
        Node<T1>* _head = nullptr;
        Node<T1>* _tail = nullptr;
        size_t _listSize = 0;
        void addEndPrivate(Node<T1>*, T1);
        void addStartPrivate(Node<T1>*, T1);
        T1 removeEnd(Node<T1>*);
        T1 removeStart(Node<T1>*);
        void walkList(Node<T1>*); // RECURSIVE FUNCTION
};


int main(int argc, char *argv[])
{
    List<int>* lList = new List<int>;

    while (true)
    {
        int number;
        cout << "Enter a number: (-999 to quit) ";
        cin >> number;

        if (number == -999) break;

        lList->addEnd(number);
    }

    cout << "Printing the list: ";
    lList->printList();

    delete lList;
    return 0;
}


template <typename T1>
void List<T1>::addEnd(T1 data)
{
    addEndPrivate(_tail, data);
}

template <typename T1>
void List<T1>::addStart(T1 data)
{
    addStartPrivate(_head, data);
}

template <typename T1>
T1 List<T1>::getEnd() // Exact same thing as pop_back().
{
    return removeEnd(_tail);
}

template <typename T1>
T1 List<T1>::getStart()
{
    return removeStart(_head);
}

template <typename T1>
void List<T1>::printList() // This function can also "walk" in reverse. See below.
{
    walkList(_head);
    cout << endl;
}

/* This is how you can "walk" backwards. All you have to do is pass the tail.
template <typename T1>
void List<T1>::printList()
{
    walkList(_tail);
    cout << endl;
}
*/

template <typename T1>
void List<T1>::walkList(Node<T1>* head)
{
    if ((_head == _tail) && (_head == nullptr)) // RECURSIVE BASE CLASS: Single node in list.
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head == nullptr) // NOT the private _head, this is the passed in head.
    {
        return;
    }

    cout << head->getData() << " ";
    walkList(head->getNext());
}

template <typename T1>
void List<T1>::addEndPrivate(Node<T1>* tail, T1 data)
{
    Node<T1>* newNode = new Node<T1>(data, nullptr, nullptr);

    if ((_head == _tail) && (_tail == nullptr)) // If the list is empty.
    {
        _head = newNode;
        _tail = newNode;
        _listSize++;
        return;
    }

    newNode->setPrev(_tail);
    _tail->setNext(newNode);
    _tail = newNode;
    _listSize++;
}

template <typename T1>
void List<T1>::addStartPrivate(Node<T1>* head, T1 data)
{
    Node<T1>* newNode = new Node<T1>(data, nullptr, nullptr);

    if ((_head == _tail) && (_head == nullptr)) // If the list is empty.
    {
        _head = newNode;
        _tail = newNode;
        _listSize++;
        return;
    }

    newNode->setPrev(_head);
    _head->setPrev(newNode);
    _head = newNode;
    _listSize++;
}

template <typename T1>
T1 List<T1>::removeEnd(Node<T1>*)
{
    //
}

template <typename T1>
T1 List<T1>::removeStart(Node<T1>*)
{
    //
}