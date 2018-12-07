DIR=../include

libfuncs.a: *.o
	ar rv $@ *.o

*.o: *.c
	gcc -g -Wall -c -I$(DIR) *.c -lrt

clean:
	rm -f *.o
