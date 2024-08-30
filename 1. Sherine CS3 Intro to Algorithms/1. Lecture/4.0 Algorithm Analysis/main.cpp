#include <iostream>

using namespace std;

/*
As a programmer, you will need to "wear" plenty of hats.
    For example, a programmer/student may need to...
        - Develop a working solution.
        - Solve a problem efficiently for a client.
        - Understand a problem for a theoretician (using the scientific method).

Running Time Analysis:
    We care because making this analysis allows us to make more efficient and better decisions in general.
    Examples include...
        The Discrete Fourier transform - break down waveform of N samples into periodic components.
        N-body simulation - Simulates gravitational interactions among N bodies.

THE CHALLENGE/QUESTION:
    Will my program be able to solve a large practical input?
        Yes, we will use the scientific method to understand performance.

The Scientific Method broken down:
    Observe features of the natural world.
    Hypothesize a model that is consistent with the observations.
    Predict events using the hypothesis.
    Verify predictions by making further observations.
    Validate by repeating until the hypothesis and observations agree.

    The SM provides a rigorous method for testing things.

In what ways does analyzing memory usage apply to the Scientific Method?
    It provides insight to how much memory you will use. It will allow you to develop the most efficient algorithms
    that apply to the problem at hand.

What are the keys principles of the Scientific Method with regards to program performance?
    Repeatablility - Replication for others.
    Proper tests of hypothesis.
    Iteration.
*/

/*
EXPERIMENTAL ALGORITHMICS:

Total Run-Time = sum of cost x frequency for all observations.

Ok, so what are the costs of basic operations?
    Int add: (a + b) 2.1 nanoseconds
    Int multiply: (a * b) 2.4 nanos
    Int divide: (a / b) 5.4 nanos
    Float add: 4.6 nanos
    Float multiply: 4.2 nanos
    Float divide: 13.5 nanos
    Sine: 91.3 nanos
    Arctangent: 129.0 nanos
        It is safe to assume that all super basic operations take approx 2.1 nanoseconds.

Most primitive operations take constant time (which is good).
*/

/*
LECTURE 8/28 START
Invarient: A varient that causes discourse of some variet. For example, on a chess board, we can fit 32 dominoes
    on the board while maintaining color parity. If someone were to remove two corner pieces diagonally from each
    other, then we would only be able to fit 30 dominoes on the board due to color parity.

We are always striving for lineartithmic or lower time when scaling algorithms.

Typically speaking, a better order of growth will result in faster operation times.

The best algorithm analyses consist of:
    Best Case: determined by "easiest" input and provides a goal for all inputs.
    Worst Case: determined by "hardest" input and provides a time-guarentee for all inputs.
    Average Case: this is the expected cost of random input, but requires a model for "random" input.

ALGORITHMIC DESIGN APPROACH:
    Start:
        Develop an algorithm.
        Prove lower bound.
    
    Gap?
        Lower the upper bound (discover a new algorithm).
        Rause the lower bound (more difficult).
    
    Golden Age of Algorithm Design:
        1970s - 1980s.
            Sherine claims the decline in algorithmic thinking is due to academia, which is a fair assessment imo.
        Steadily decreasing upper bounds for many important problems.
            Now we know many optimal algorithms.
    
    Caveats:
        Are we being overly pessimistic to focus on worst case?
        Need better than "to within a constant factor" to predict performance.

Algorithms have improved over time because of programmer's pessimisitic approach towards algorithms.
    Sherine states that the worst case scenario shouldn't be your main focus, but it should be considered.
*/

/*
COMMONLY USED NOTATIONS IN THE THEORY OF ALGORITHMS
    Tilde: "~", used for the leading term. ~10N^2. Is used to provide approximate model.
    Big Theta: provides asympototic order of growth, and is used to classify algorithms.
    Big Oh: Used to develop upper bounds.
    Big Omega: Used to develop lower bounds.
COMMON MISTAKES:
    Interpreting Big Oh as an approximate model.

    This course will primarily use Tilde notation.
*/

/*
Memory requirements also need to be considered.

*/

int main(int argc, char *argv[])
{
    
    return 0;
}