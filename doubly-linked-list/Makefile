CC=gcc
CCFLAGS=-g -pedantic -Wall

OBJS=demo.o llist.o

all: $(OBJS)
	$(CC) $(CCFLAGS) -o demo $(OBJS)
.c.h:
	$(CC) $(CCFLAGS) -c $(OBJS)
clean:
	rm $(OBJS) demo

