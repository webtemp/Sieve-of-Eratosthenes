PROGNAME = sieve
OBJS = sieve.o
CC = g++
RM = rm -f
DEBUG = -g
CFLAGS = -Wall -O2 -std=c++11 -DSENTRY_DEBUG -c 
LFLAGS = -Wall -O2 -std=c++11 -DSENTRY_DEBUG

sieve : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PROGNAME);
	$(RM) *.o *.~

sieve.o:
	$(CC) $(CFLAGS) sieve.cpp

clean:
	$(RM) *.o *~ sieve

