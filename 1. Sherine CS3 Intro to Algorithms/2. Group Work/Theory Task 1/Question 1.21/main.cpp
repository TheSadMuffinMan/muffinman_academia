/*
Question 1.21:
    Show that Property 1.3 holds for the algorithm described in Exercise 1.20.

    Property 1.3:
        The weighted quick-union algorithm uses AT MOST a constant times M lg N instructions to process M edges
            on N objects. The alternative (quick-find and sometimes quick-union) uses AT LEAST (M*N)/2 instructions.
            This guarentees that we can solve huge practical problems in a reasonable amount of time.

Exercise 1.20:
    Modify Program 1.3 (Weighted Quick Union) to use the height of the trees (longest path from any node to the root),
        instead of the weight, to decide whether to set id[i] = j or id[j] = i. Run empirical studies to compare this
        variant with Program 1.3 (Unmodified Weighted Quick Union).

*/