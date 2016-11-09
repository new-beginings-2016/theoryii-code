CC = gcc

OBJS = dfa.o

all: dfa

dfan: $(OBJS)
	$(CC) -o dfa $(OBJS)
.c.o:
	$(CC) $(CFLAGS) -g -Wall -c $<
	
clean:
	rm -f dfa *.o core
