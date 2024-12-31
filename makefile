# Makefile for SnakeGame project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Directories
SRC_DIR = .
BUILD_DIR = build

# Source files
SRCS = $(SRC_DIR)/Bomb.cpp \
       $(SRC_DIR)/Fruit.cpp \
       $(SRC_DIR)/GameObject.cpp \
       $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/Menu.cpp \
       $(SRC_DIR)/Poison.cpp \
       $(SRC_DIR)/SnakeGame.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable
OUT = $(SRC_DIR)/SnakeGame.exe

# Default target
all: $(OUT)

# Rule to build the final executable
$(OUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUT)

# Rule to compile .cpp files to .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJS) $(OUT)

.PHONY: all clean
