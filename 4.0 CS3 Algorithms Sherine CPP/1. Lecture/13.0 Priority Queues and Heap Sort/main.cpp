/*
Priority Queues use a binary heap data structure.
    Our goal is to insert items, and then remove either the largest or smallest item.

    EXAMPLE:
*insert "P"*
*insert "Q"*
*insert "E"*
return max;
    *returns "Q"* etc...

Client Example Problem:
    "Find the largest M items in a stream of n items."
*/

/*
Using BINARY TREES/BINARY HEAP for Priority Queues:
A COMPLETE TREE: all nodes are present and pushed to the left-most leaf spot.
    The tree will be perfectly balanced EXCEPT for the lowest levels.

BINARY HEAP:
    Array representation of a heap-ordered complete binary tree.
    Parent's key must be larger than children's keys.
    Tree must be complete to work properly.
    Generally, you want to start your indices to start at 1.

    Children nodes will ALWAYS be...
        Left Node = (2 * parent);
        Right Node = ((2* parent) + 1);
    The largest key will always be at array[1].

    When adding a new node, we ALWAYS add it to the next available legal spot.
        From there, the node either SINKS or SWIMS through the array to its correct spot.
*/

/* VISUAL REPRESENTATION (of minimum binary heap):

             10
         /       \
        15        30
      /   \     /    \
    40    50   100   40

*/

/* HEAP SORT
Heap Sort uses a bottom up sorting method.
Is VERY space-efficient: is an in-place, unstable, sorting algorithm.

Has a GUARANTEED O(n*log(n)) run time efficiency.

    SHERINE LECTURE CODE (Java implementation)
public void sort(String[] a)
{
    int n = a.length;
    MaxPQ<String> pq = new MaxPQ<String>();

    for (int i = 0; i < n; i++)
        pq.insert(a[i]);
    for (int i = n-1; i >= 0; i--)
        a[i] = pq.delMax();
}

    Class Java Implementation
public class Heap
{
    public static void sort(Comparable[] a)
    {
    int n = a.length;
    for (int k = n/2; k >= 1; k--)
    {
        sink(a, k, n);

        while (n > 1)
        {
            exch(a, 1, n);
            sink(a, 1, --n);
        }
    }
    
    private static void sink(Comparable[] a, int k, int n)
    { //as before }
    private static boolean less(Comparable[] a, int i, int j)
    { //as before }
    private static void exch(Object[] a, int i, int j)
    { //as before }
}
*/

template <class DataType>
class PriorityQueue
{
    public:
        PriorityQueue()
        {
            _size = 0;
            _isEmpty = 1;
        }
        DataType buildPQueue(DataType[]);
        
    
    private:
        int _size;
        bool _isEmpty;
};

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}