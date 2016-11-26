CC = gcc
CCFLAGS=-Wall -pedantic -g
OBJS = demo.o heap.o 


demo: $(OBJS)
	$(CC) -o demo $(OBJS)
.c.o:
	$(CC) $(CCFLAGS) -g -Wall -c $<
clean:
	rm -f demo $(OBJS)
