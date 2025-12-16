# Compiler name:
CXX = g++

# C++ compiler flags:
CXXFLAGS = -c -g -Wall -std=c++17

# The build target executable file; .exe is not required.
PROGRAM = main.exe

# List all .cpp files separated by space:
CPPFILES = main.cpp

# `make all` default rule that will run when we input "make".
# First compile each file to object file, then make a single binary program.
all:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# `make clean` Rule:
# Deletes object and binary files.
clean:
	rm -f $(PROGRAM) *.o

# `run` and `test` Rules:
run:
	./$(PROGRAM)

test:
	./$(PROGRAM) test