CC = gcc
CCFLAGS=-Wall -pedantic -g
OBJS = stest.o stack.o

all: stest

stest: $(OBJS) 
	$(CC) -o stest $(OBJS) 
.c.o:
	$(CC) $(CFLAGS) -g -Wall -c $<
clean:
	rm -f stest $(OBJS)
