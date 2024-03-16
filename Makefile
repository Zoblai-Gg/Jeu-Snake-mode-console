CC = gcc

CFLAGS = -g

SRC = $(wildcard *.c)

OBJ =$(SRC:.c=.o)

all : snake

%.o : %.c
	$(CC) -o $@  -c $<


snake : $(OBJ)
	$(CC) -o $@ $^

clean :
	rm -rf *.o snake