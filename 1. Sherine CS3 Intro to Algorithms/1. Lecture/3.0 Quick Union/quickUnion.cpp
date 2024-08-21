#include <iostream>

using namespace std;

/*
TLDR: A good algorithm will make or break your program.
    Just because you have a piece of code that works does not mean that it is quality work.
*/

/*
Data structure:
    Integer array id[] of length N.

Interpretation:
    id[i] is parent of i.

Root of i is id[id[id[...id[i]...]]].

Find: What is the root of p?
    The root of 3 is 9.
    Root of 5 is 6.
    3 and 5 are not connected.
Connected: do p and q have the same root?

     0  1   2   3   4   5   6   7   8   9
id[] 0  1   9   4   9   6   6   7   8   9

    0   1       6   7   8   
        9       |
       / \      5
      2   4
          |
          3

Defects of quick-union:
    Trees can get tall.
    Find/Connected is too expensive (N array accesses).
Ok.. So how do we improve this? Weighting!

WEIGHTED QUICK-UNION:
    Is a modified quick-union that avoids tall trees.
    Keeps track of size of ea tree (number of objects).
    Balance by linking root of smaller tree to root of larger tree.

Running Time.
    Find: Takes time proportional to depth of p.
        Depth of any nore x is at most lg(N).
            Is essentially repetitively dividing by 2.
    Union: takes constant time, given roots.
*/

class QuickUnionUF
    {
    private:
        int* id;

    public:
        QuickUnionUF(int N)
        {
            id = new int[N];
            for (int i = 0; i < N; i++)
            {
                id[i] = i;
            }
        }

        int find(int i)
        {
            while (i != id[i])
            {
            i = id[i];
            }
        return i;
        }

        void unionElements(int p, int q)
        {
            int i = find(p);
            int j = find(q);
            id[i] = j;
        }
        ~QuickUnionUF()
        {
        delete[] id;
        }

        /*
        These lines are all that is needed to switch from quick-union to weight quick-union.
        functionName()
        {
            int i = find(p);
            int j = find(q);
            if (i == j) return;
            if (sz[i] < sz[j])
            {
                id[i] = j; sz[j] += sz[i];
            }

            else
            {
                id[j] = i; sz[i] += sz[j];
            }
        }
        */
};