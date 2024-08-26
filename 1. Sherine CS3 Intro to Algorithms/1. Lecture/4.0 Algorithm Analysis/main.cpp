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

Most primitive operations take constant time (which is good).
*/

int main(int argc, char *argv[])
{
    
    return 0;
}