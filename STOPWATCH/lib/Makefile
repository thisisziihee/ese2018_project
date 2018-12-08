AR=ar
CC=gcc
CFLAGS=-g -Wall
LIB=libfunc_sw.a
DIR=../include

$(LIB): *.o
	$(AR) rv $@ *.o

*.o: *.c
	$(CC) $(CFLAGS) -c $< -I$(DIR) *.c -lrt -lm

clean:
	rm -f *.o $(LIB)

