# Decimal Deletion
https://open.kattis.com/problems/decimaldeletion

## Problem:
After solving one too many optimisation problems, Joshua has developed a phobia for floating point numbers. Help him out by rounding some floating point numbers into normal, safe integers.

### Input
The first and only line of input will be a decimal number 0 ≤ N ≤ 10000.

### Output
Print the integer closest to the given input. If the given input is exactly between two integers, any of them will be accepted.

> **Input 1:** `3.14` ---> **Output 1:** `3`  \
> **Input 2:** `2.71` ---> **Output 2:** `2`  \
> **Input 3:** `2.5` ---> **Output 1:** `3`  \
> **Input 4:** `16` ---> **Output 1:** `16`

## Development Notes
- C-Strings end at the first `\0`.
- After getting a running program that passes all of *my* test cases, Kattis denied the first few tries. I think this is because I am passing arguments directly to the program (inside `argv[1]`) instead of taking them from a "user".
    - Yep, this ended up passing all test cases. I feel like this isn't proper technique... It should be this:
```c++
int main(int argc, char* argv[])
{
    // Starts at 1 b/c program name is stored in argv[0].
    for (int i = 1; i < argc; ++i)
    {
        std::string num = argv[i];
        round_number(num);
        std::cout << num << " ";
    }
    return 0;
}
```

