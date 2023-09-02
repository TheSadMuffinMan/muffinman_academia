/*
The full specification of the class is:
  A data member counter of type int.
  A data member named limit of type int.
  A constructor that takes two int arguments and assigns the first one to counter and the second one to limit.
  A function called increment that accepts no parameters and returns no value. If the data member 
    "counter" is less than limit, increment just adds one to the instance variable counter.
  A function called decrement that accepts no parameters and returns no value.
    If counter is greater than 0, decrement subtracts one from the counter.
  A function called getValue that accepts no parameters. It returns the value of the instance variable counter.

Don’t include the header file in this exercise, because REVEL assumes that the header and implementation are 
  placed in the same file.
*/

#include "counter.h"

Counter::Counter(int theCounter, int theLimit)
{
  counter = theCounter;
  limit = theLimit;
}

void Counter::increment()
{
  if (counter < limit)
    counter++;
}

void Counter::decrement()
{
  if (counter > 0)
    counter--;
}

int Counter::getValue()
{
  return counter;
}