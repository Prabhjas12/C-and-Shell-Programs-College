CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

all: growing_arrays test_growing_arrays

growing_arrays: growing_arrays.c growing_arrays.h
	$(CC) $(CFLAGS) -o growing_arrays growing_arrays.c

test_growing_arrays: test_growing_arrays.c growing_arrays.h
	$(CC) $(CFLAGS) -o test_growing_arrays test_growing_arrays.c

clean:
	rm -f growing_arrays test_growing_arrays
