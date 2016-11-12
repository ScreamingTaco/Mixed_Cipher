OBJS = cipher.cpp main.cpp
CC = g++
COMPILER_FLAGS = -Wall -std=c++14
OBJ_NAME = cipher
all:$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
