# Author: Ding Zhou
# Date: October 5, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o game.o thinkadot.o flipflop.o tools.o
TARGET = tad
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
main.o: main.cpp game.hpp tools.hpp
game.o: game.cpp game.hpp thinkadot.hpp
thinkadot.o: thinkadot.cpp thinkadot.hpp flipflop.hpp
flipflop.o: flipflop.hpp
tools.o: tools.cpp tools.hpp
