OBJS = cipher.cpp main.cpp
CC = g++
COMPILER_FLAGS = -Wall -std=c++14
OBJ_NAME = cipher_test
all:$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
