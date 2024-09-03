# To compile and run, navigate to file repo and input "python 3 *filename*.py".
# <-- Pound key is for comments.
# "\" is an escape key.
# One main difference that Python has is the lack of data type declaration. Is kinda nice I guess.

# User defined functions
def addNums(x,y):
    sum = (x + y)
    return sum

print("Program start.\n")

num1 = int(input("Please input an int to continue: ")) # Variable declaration and user input.

print("You input: ", num1)