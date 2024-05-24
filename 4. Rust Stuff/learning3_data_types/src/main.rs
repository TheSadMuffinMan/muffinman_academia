// https://www.youtube.com/watch?v=t047Hseyj_k

fn main()
{
    let tup: (i32, char, bool) = (1, 't', true); // This is a tuple. Can use "mut" to change them.
    println!("tup.0: {}\n", tup.0); // This works the same exact way as in C++, even with pointers.
    println!("tup.1: {}\n", tup.1);
    println!("tup.2: {}\n", tup.2);
    // If you make the tuple mutable, the . operator allows us to change the elements inside the tuple.

    let _arr = [1, 2, 3, 4, 5]; // Implicit array definition.
    println!("Index at array 0: {}\n", _arr[0]);

    // Explicit array definition: <Array Name>: [<Data Type>; <Num of Elements>] = [data, data, ...];
    let defined_arr: [i32; 5] = [6, 7, 8, 9, 10];
    println!("Defined array at index 0: {}\n", defined_arr[0]);

    /* You CAN initialize arrays with no values, see below.
        let mut valueless_arr: [i32, 4];
            This is useful when we want to drop data into the array.
    */

    println!("\nProgram complete.");
}

/*
PRIMITIVE DATA TYPES: the basic or fundamental data tyes used to declare a variable.
    There are two types of data in Rust: SCALAR and COMPOUND types.
SCALAR DATA TYPE: data that has a finite set of possible values, meaning that each value can be compared to
    any other values as either =, <, or >.
    Examples include integers, floating-point values, booleans, and chars.
COMPOUND DATA TYPE: any data type which can be constructed in a program using the programming language's
    primitive data types and other composite types.
    Examples include arrays and tuples.
*/

/*
Scalar Data Types:

Integers: all whole numbers (no decimals).
    let x: i<Number of bits> = 32;

    Integers use the first bit to signify if the # is > or < 0.
    i32 is the DEFAULT INTEGER in Rust.
        i32 range: -2 billion to 2 billion (-2,147,483,648 to 2,147,483,647).
            To find ranges of data types, we input...
                let x = (<Data Type>::MAX); print x;
    Rust also uses i8, i16, i32, i64, and i128.

Unsigned Integers: all positive whole numners.
    let x: u<Number of bits> = 32;

    u32 is default unsigned int.
    u32 range: 0 to 4.25 billion (0 to 4,294,967,295, == [(2^32) - 1]).

Floating-Point Values:
    let x: f32/f64 = 3.141569;

    f32 == Single Precision.
    f64 == Double Precision, is the default in Rust.

Boolean:
    let true_or_false: bool = false;

    false == 0;
    true == 1;

Chars: same as C++.
    let x: char = 'a';
*/

/*
Compound Data Types:

TOUPLES: a fixed length sequence of elements. Elements do not have to be the same data type.

ARRAYS: Same exact as above, but elements ARE all the same data type.
    Arrays behave the exact same way in C++, but are explicitly defined a little different.
*/