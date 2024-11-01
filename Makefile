# Compiler
CC = gcc

# Complier flags
CFLAGS = -Wall -g

# Libraries
LIBS = -lncurses

# Source files
SRC = $(wildcard src/*.c)

# Binary
TARGET = pluto

# Build
all: $(TARGET)

$(TARGET) : $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Clean binary
clean:
	rm -rf $(TARGET)
