# Author: Ding Zhou
# Date: Oct 26, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o simulator.o tools.o
TARGET = consensus
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
main.o: main.cpp simulator.hpp tools.hpp
simulator.o: simulator.hpp simulator.cpp agent.hpp tools.hpp
