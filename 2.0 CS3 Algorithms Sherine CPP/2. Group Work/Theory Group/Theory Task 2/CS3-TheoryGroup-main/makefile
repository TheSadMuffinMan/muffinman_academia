CXX = g++

CXXFLAGS = -c -g -Wall -std=c++17 -pedantic

PROGRAM = main
CPPFILES = main.cpp bitfield.cpp parser.cpp logger.cpp

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

clean:
	rm -rf $(PROGRAM) *.o

run:
	./${PROGRAM}

runf:
	./$(PROGRAM) "./input/A Scandal In Bohemia.txt"

runt:
	./$(PROGRAM) "./input/test.txt"