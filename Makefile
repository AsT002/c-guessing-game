# Compiler to use
CC = gcc

# Compiler flags
#  -Wall and -Wextra enable common compilation warnings
#  -g includes debugging symbols
CFLAGS = -Wall -Wextra -g

# Source file
SRC = main.c

# Name of the final executable
EXE = guessing_game

# Default make target
all:
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)

# Clean up the final executable
clean:
	rm -f $(EXE)

# Phony targets to avoid conflicts if files named "clean" or "all" exist
.PHONY: all clean
