OBJS=adjacency_matrix.o demo.o
CC=gcc
CCFLAGS=-g -pedantic -Wall

demo: $(OBJS)
	$(CC) $(CCFLAGS) -o demo $(OBJS)
    
.c.o:
	$(CC) $(CCFLAGS) -c $<

clean:
	rm $(OBJS) demo
