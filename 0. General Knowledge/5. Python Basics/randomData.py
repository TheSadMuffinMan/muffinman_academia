import random

def main():
    print("\nProgram creates a random data set in the form \"x *SPACE* y.\"\n")
    setSize = int(input("How many data sets would you like?: "))

    z = int(0)
    while (z < setSize): # This is a while loop because for loops are annoying af in python.
        x = random.randrange(setSize)
        y = random.randrange(setSize)

        while (x == y):
            y = random.randrange(setSize) # Ensuring x & y do not equal each other.

        z = (z + 1)
        displayString = (str(x) + " " + str(y))
        print(displayString)

main()