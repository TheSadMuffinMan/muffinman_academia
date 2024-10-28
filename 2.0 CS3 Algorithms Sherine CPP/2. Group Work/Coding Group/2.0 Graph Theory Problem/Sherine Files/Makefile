# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -std=c++17

# Target executable name
TARGET = shortest_paths

# Source files
SRC = main.cpp Digraph.cpp BreadthFirstSearch.cpp SelfResizingArray.cpp

# Object files (generated from source files)
OBJ = $(SRC:.cpp=.o)

# Rule for building the final executable
all: $(TARGET)

# Rule for linking object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rule for compiling source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)
    
