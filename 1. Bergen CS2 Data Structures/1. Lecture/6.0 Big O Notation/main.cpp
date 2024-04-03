// Big O notation describes the complexity of a system.
// O(x) stands for "Order (x)".
// O(1) "Order 1" (Constant time). All operations take the same time. Assignment operators (x = 42) are best example.
// O(n) "Order n" (Linear time). It depends on input N for however long the calculation will take. Loops are best example.
// O(n^2) "Order n squared" (Quadratic time). Example is a nested for loop.
// O(n^3) "Order n cubed" (Cubic time).
// Can be calculated with a simple equation. See below.
// for (i in [N])
//  if (j in [M])
//     if (i == j)
//      cout << j;
// This would result in T(n) = O(1) + O(1) + O(M) * O(n)
// (Solving above) T(n) = O(m*n) --> T(n) = O(m^2) (M and N are the same)

// O(2^n) "Order 2 to the n" (Exponential time). You DO NOT want exponential increases in time. Recursion an example of this.
// An actual example of exponential notation is the Fibonacci sequence.
// fibonacci(n)
    // {
        // if ((n == 0) || (n == 1)) return n;
    // }
//    fibonacci(n - 2) + fibonacci(n - 1);

// O(log n) "Order Log N" (Logarithmic time). Log functions more or less have a horizontal asymptote, which means that
// The larger the number, the more efficient your algorithm. Binary search algorithms are best example.

// O(n log n) "Order n log n". An example of this would be a sorting algorithm.

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    return 0;
}