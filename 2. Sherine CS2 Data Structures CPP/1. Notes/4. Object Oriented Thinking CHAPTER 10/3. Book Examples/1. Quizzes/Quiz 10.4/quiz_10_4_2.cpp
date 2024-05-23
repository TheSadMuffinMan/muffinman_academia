/*
Assume a class Window with accessor function getWidth that accepts no parameters and returns an int.
Assume further an array of 3 Window elements named winarr, has been declared and initialized.
Write a sequence of statements that prints out the width of the widest window in the array.
*/

int maxIndex = 0;
for (int i = 1; i < 3; i++)
  if (winarr[i].getWidth() > winarr[maxIndex].getWidth())
    maxIndex = i;
cout << winarr[maxIndex].getWidth() << endl;