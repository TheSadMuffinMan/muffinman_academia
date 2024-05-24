// Comments work the same way as in C++.
fn main()
{
    println!("Hello, world!");
}

/*
To "properly" compile and run this code, first navigate to where the program is located in your terminal.
Instead of using the "rustc <Program Name>" command, input the "cargo build" command.
    This command compiles and builds our executable program.
    If you type "ls", you'll several new files.
cd into "target" directory.
cd into "debug" directory.
    ./<Program Name>
    This will run the program.
*/

/*
Alternatively, a faster way to compile and run your code is to input "cargo run" inside of the cargo's main directory.
*/

/*
Another very useful terminal command is "cargo check" (when inside base directory).
    This command checks if your code will compile without actually compiling the program.
*/

/*
The last terminal command that this episode covered is "rustfmt <Program Name>" (inside src/main.rs directory).
    This command reformats your code to be more "proper".
*/