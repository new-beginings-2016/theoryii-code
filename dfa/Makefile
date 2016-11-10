CC=gcc
CCFLAGS=-g -Wall -pedantic

OBJS=dfa.o demo.o

demo: $(OBJS)
	$(CC) -o demo $(OBJS)

.c.o:
	$(CC) $(CCFLAGS) -c $<
	
clean:
	rm -f dfa *.o core
