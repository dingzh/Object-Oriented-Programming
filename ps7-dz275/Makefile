# Author:  Ding Zhou
# Date:    Dec 8, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o Block.o Serial.o SPtr.o simulator.o population.o agent.o tools.o
TARGET = blockchain
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
Block.o: Block.cpp Block.hpp SPtr.hpp Serial.hpp tools.hpp
Serial.o: Serial.cpp Serial.hpp
SPtr.o: SPtr.cpp SPtr.hpp Block.hpp
simulator.o: simulator.hpp simulator.cpp population.hpp agent.hpp tools.hpp
population.o: population.hpp population.cpp agent.hpp tools.hpp
agent.o: agent.hpp agent.cpp
tools.o: tools.hpp tools.cpp
