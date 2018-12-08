AR=ar
CC=gcc
CFLAGS=-g -Wall
LIB=libfuncs.a
DIR=../include

$(LIB): *.o
	$(AR) rv $@ *.o

*.o: *.c
	$(CC) $(CFLAGS) -c $< -I$(DIR) *.c -lrt

clean:
	rm -f *.o $(LIB)

