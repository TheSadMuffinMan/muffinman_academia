fn main()
{
    let x = 10_000_000_000u128; // Casting 10 billion to be an unsigned 32 bit int.
    // Adding underscores to numbers makes your code more readable, see above.

    let y = -32_i64; // Adding an underscore makes your code more readable.

    let z = -1_000 as i16;
    /*
    This is the primary way to caste data members inside implementations, for example:
        let a = b / (c as i64);
    
    The best practice is to caste your "smallest" data member to the bigger member so that we
        avoid overflows.
    */

    println!("\nProgram complete.");
}
