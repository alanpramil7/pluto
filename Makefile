CC = gcc
CFLAGS = -Wall -std=c99

LDFLAGS = -lncurses 

TARGET = pluto

SRCS = $(wildcard src/*.c src/ui/*.c)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean: 
	rm -rf $(TARGET)
