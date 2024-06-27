# compiler name
CXX = g++

# C++ compiler flags
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = mainProgram.out

# list all .cpp files separated by space
CPPFILES = lectureMain.cpp

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary program
all:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o

# FIXME
# Add a rule to run the program
run:
	./$(PROGRAM)

test:
	./$(PROGRAM) test