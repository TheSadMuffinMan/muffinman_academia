/* Notes that I keep referencing
CALLING FUNCTIONS NOTES
    return_type function_name(parameter_list) {
        Body of function
        whatever you want the function to do
    }
        Return_type: A function may return a value. The return type is the data type of the value
        the function returns. Some functions perform operations without returning a value
        (voids). When determining the return type, simply ask yourself "What do I need back from this
        function?" and make that your type.

        Function_name: This is the actual name of the function. The function name and the parameter
        list together constitute the function signature. To call a function, its name is used.

        Parameter_list: the values that the function itself will be using.

        The reason you have to put the function before main is because the function has to be pre-defined.
        f(x) is another way to represent functions (in your mind).
            Voids will almost always stand alone in a single line.


PASS BY REFERENCE
    Pass by reference requires a variable unless it is a const variable.


variable.at()
    This is how to make sure that your array's do not access anything that is outside of their parameters.
    cout << "The length of your string is: " << fullName.length() << endl;
    for(size_t i = 0; i < fullName.length()+1; i++){
        cout << "fullName[" << i << "]: " << fullName[i] << endl;
        cout << "fullName.at(" << i << "):" << fullName.at(i) << endl;
*/