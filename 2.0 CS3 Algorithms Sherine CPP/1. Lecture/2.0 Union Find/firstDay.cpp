#include <iostream>

/*
***WE ARE USING CLANG FOR COMPILATION*** not gcc.

This class is supposed to be highly theoretical.
Textbook is our bible.
If something is said in class, it is fair game.
Notes will be asked for when presenting things.

Tests will generally happen on Fridays, will take approx 10 min.
Quizzes will be notified on Wednesdays (for next week's Friday).
***ONE LINE ANSWERS WILL BE GRADED AS A ZERO***
Attendence is required (technically he requires 90%). Just show up lol.
Arriving late will be considered an absence.

Assessments - Will be group work. Will have two groups - coding groups and theoretical groups.
Teamwork is a must, as that is how you will work as professionals.

Expectations:
LaTeX is the standard. ***NEED TO RESEARCH*** (is on D2L).
Any kind of handwriting will be digital (use iPad).
Proper writing/English is required. Just don't be an idiot when typing.

This course aims to change us from code writers into programmers.
30% of code shown will be in C++, and other languages we will see are Python and Java.
Textbook uses C.

SOURCES:
Do NOT use AI. (It's worthless anyways lol)

Office Hours:
1300-1500 (Monday), 1300-1400 (Wed), 0900-1100 (Friday)
Will require an appointment (because his CS1&2 classes are MASSIVE).

Tech synergy happens on Wednesdays at 1600.

Spend time on Week 1 - LaTeX
Code should be styled nicely. Brackets should line up with ea/other.
***Learn Doxygen Comments (Is an organizational type I think).
Examples of LaTeX code can be found in D2L Week 1.

The scientific model approach to problems is how we will be attacking problems this semester.
Header files will be treated the same way that Bergen treated them - don't touch 'em!
*/


/* ACTUAL LECTURE START
CHAPTER/UNIT 1.5: Union-Find & Dynamic Connectivity Problem

Dynamic Connectivity Problem: Given a set of N objects, supports two operations.
    Connect two objects.
    Is there a path connecting the two objects?

0   1---2   3---4
            |   |
5---6   7   8   9

Questions to ask:
    Are 0 and 7 connected? NO
    Are 8 and 9 connected? YES
    etc

Applications of Union-Find:
    Pixels in a digital photo.
    Computers in a network.
    Frind in a social network.
    Transistors in a computer chip.
    Elements in a mathmatical set.
    Variable names in a Fortran program.
    Metallic sites in a composite system.

MODELING THE CONNECTIONS:
We assume "is connected to" is an equivalence relation:
    Reflexive: p is conected to p.
    Symmetric: if p is connected to q, the q is connected to p.
    Transitive: if p is connected to q and q is connected to r, the p is connected to r.

IMPLEMENTING THE OPERATION:
    Find: In which component is object p?
    Connected: Are objects p and q in the same component?

Union-Find data type (API) Psuedo-Code
class UF
    {
    UF(int N)
    void union(int p, int q)
    int find(int p)
    bool connected(int p, int q)
    *Plus other stuff to make it work*
    }
*/

/*
QUICK FIND (AKA "eager approach")
Uses arrays where the index represents the objects.
Data structure:
    Interger array id[] of length N.
    Interpretation: id[p] is the id of the component containing p.

        0   1   2   3   4   5   6   7   8   9
id[]:   0   1   1   8   8   0   0   1   8   8

Find- What is the id of p?  id[6] = 0; id[1] = 1.
Connected - do p and q have the same id? 6 and 1 are not connected.

This approach is problematic with large data sets because there can be too many values to change at one time.
For the union of 5 and 6, the below array changes to...
        0   1   2   3   4   5   6   7   8   9
id[]:   0   1   2   3   4   5   6   7   8   9
        CHANGED TO.... [union5,6]
        0   1   2   3   4   5   6   7   8   9
id[]:   0   1   2   3   4   5   5   7   8   9
The key starting point to union-find is initializing the array with proper increments inside (0,1,2,3...).

Quick-Find implementation is in Sherine's Lecture.
*/

/*
Sherine wants us to be at Tech Snyergy to help set up coding environment. LLVM compilor is the end goal.
    Is worth 3% extra credit if you finish in any place other than last.

Any code you write must be your own writing.
Cmath, Clib, iostream (but no sorting), cmath, and cstring.
    If you need to resize an array, you do it yourself.
*/