CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: coolness

coolness: $(OBJECTS)
	$(CC) $(CFLAGS) -o coolness $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f coolness $(OBJECTS)
