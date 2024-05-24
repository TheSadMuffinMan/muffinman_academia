// Learned from https://www.youtube.com/watch?v=xYgfW8cIbMA

fn main()
{
    let _a = 4; // Implicit type assignment: the compiler decides the data type.
    // x = "hello"; // This will NOT work because Rust does not allow you to change data types.

    let b: u32 = 6; // Explicit type assignment: we decide the data type.

    println!("_a is: {}\nb is: {}\n", _a, b);

    let mut _c = 10; // Mutable variable: _c's data can be changed.
    println!("_c = {}\n\nChanging _c's value...\n", _c);

    _c = _c + 5;
    println!("\"New\"_c = {}\n", _c);

    println!("Program complete.");
}

// Rust newline == C++ newline.

/*
Rust is a stacically and strongly typed programming language.
    This means that when you define a variable, the compiler assigns a data type.
    By default, Rust will implicitly decide variable data types.
*/

/*
By default, variables are Immutable.
    This means that all variables are constants and cannot be changed.
To change this, the "mut" (mutable) keyword must be used. Syntax below.
    let mut x = 4;
    ... code ...;
    x = 5;
    println!("x is: {}", x);
        TERMINAL: x is 5
*/

/*
One unique quirk about Rust is that overwriting variables is commonplace.
    let x = 4;
    ... code ...
    let x = 5;
        At first glance, we wouldn't think that this would work, but Rust allows us to override/reuse
            variables with ease.
        This allows us to "get around" mutability issues by simply redefining variables to their
            desired values.
*/

/*
Scope is very important!!

fn main() {
    let x = 4;
    print;

    {
        let x = 2; // This is known as Variable Shadowing: we are manipulating x inside this scope only.
        // x is only == 2 inside the braces!!
        print;
    }

    let x = x + 1;
    print;
}
TERMINAL:
x = 4
x = 2
x = 5
*/