/* Accepted
Write the header file (.h file) of a class Counter containing:

  A data member counter of type int.
  A data member named counterID of type int.
  A static int data member named nCounters.
  A constructor that takes an int argument.
  A function called increment that accepts no parameters and returns no value.
  A function called decrement that accepts no parameters and returns no value.
  A function called getValue that accepts no parameters and returns an int.
  A function named getCounterID that accepts no parameters and returns an int.
*/

class Counter
{
public:
  Counter();
  Counter(int);
  int counter, counterID;

  void increment();
  void decrement();
  int getValue();
  int getCounterID();
  
private:
    static int nCounters;
};