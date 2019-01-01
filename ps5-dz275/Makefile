# Author: Ding Zhou
# Date: Nov 10, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o simulator.o population.o agent.o tools.o
TARGET = consensus2
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
main.o: main.cpp simulator.hpp population.hpp tools.hpp
simulator.o: simulator.hpp simulator.cpp population.hpp agent.hpp tools.hpp
population.o: population.hpp population.cpp agent.hpp tools.hpp
agent.o: agent.hpp agent.cpp
