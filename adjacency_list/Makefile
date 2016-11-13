CC = gcc
CCFLAGS=-Wall -pedantic -g
OBJS = demo.o adjacency_list.o llist.o

all: $(OBJS)
	$(CC) $(CCFLAGS) -o demo $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -g -Wall -c $<
clean:
	rm -f demo $(OBJS)
