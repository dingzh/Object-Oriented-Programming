# Author:  Ding Zhou
# Date:    Dec 1, 2018
# Revised: Dec 1, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o Driver.o Block.o Serial.o SPtr.o tools.o
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
main.o: main.cpp Driver.hpp tools.hpp
Driver.o: Driver.cpp Driver.hpp Blockchain.hpp tools.hpp
Block.o: Block.cpp Block.hpp SPtr.hpp Serial.hpp tools.hpp
Serial.o: Serial.cpp Serial.hpp
SPtr.o: SPtr.cpp SPtr.hpp Block.hpp
tools.o: tools.hpp tools.cpp
