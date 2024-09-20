# To compile and run, input "python3 randomData.py > tee"
import random

def main():
    # print("\nProgram creates a random data set in the form \"x *SPACE* y.\"\n")
    # setSize = int(input("How many data sets would you like?: "))

    setSize = 100000
    z = int(0)
    while (z < setSize):
        x = random.randrange(setSize)
        y = random.randrange(setSize)

        while (x == y):
            y = random.randrange(setSize) # Ensuring x & y do not equal each other.

        z = (z + 1)
        displayString = (str(x) + " " + str(y))
        print(displayString)

main()