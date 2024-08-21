class QuickFindUF
{
    private:
        int* id;
        int size;

    public:
        QuickFindUF(int N)
        {
            size = N;
            id = new int[N];

            for (int i = 0; i < N; i++)
            {
                id[i] = i;
            }
        }

        bool find(int p)
        {
            return id[p];
        }

        void Union(int p, int q)
        {
            int pid = id[p];
            int qid = id[q];

            for (int i = 0; i < size; i++)
            {
                if (id[i] == pid)
                {
                    id[i] = qid;
                }
            }
        }

        ~QuickFindUF()
        {
            delete[] id;
        }
};

/*
***NOT SUITABLE FOR LARGE PROBLEMS*** (memory queing results in quadratic time results)
    10^9 operations for 10^9 data set.
    For single queries, the quick find algorithm is linear.

Defects of quick-find:
    Union operation is too expensive (N array accesses).
    Trees are flat, but it is too expensive to keep them flat.

*/