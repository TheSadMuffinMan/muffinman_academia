// https://www.youtube.com/watch?v=PQBX-ev5q2k

use std::io; // This is importing the input/output Module from the std Crate.

fn main()
{
    // Calls the String constructor and initializes it to a null value.
    let mut user_input = String::new();

    /* Creates a mutuable reference to user_input which allows read_line to directly modify the data
        inside of user_input:

    io::stdin().read_line(&mut user_input);
    However, with input, we should include the ".expect(...)" suffix for error catching. See below.
    */
    println!("Input a string: ");
    io::stdin().read_line(&mut user_input).expect("Failed to read input."); // Behaves the same as std::getline (C++).

    println!("You input: {}", user_input);

    println!("\nProgram complete.");
}

/*
Every Rust file includes a PRELUDE: the list of things that Rust automatically imports into every program.
    It's kept as small as possible, and is focused on traits which are used in almost every single Rust program.
        This is functionally the same thing as using the STL in C++.
    One thing the Prelude does NOT have is a standard way to capture user input.
    Because of this, we must import the io Module from the std Crate.
        CRATE: == C++ library.
        MODULE: specific portion of a Crate.
*/