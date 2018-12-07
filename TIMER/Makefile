all: libfuncs.a main_timer

libfuncs.a: *.o
	ar rv $@ *.o

main_timer: main_timer.o libfuncs.a
	gcc -g -Wall -o main_timer main_timer.c -L. -lfuncs -lrt

*.o: *.c
	gcc -g -Wall -c *.c -lrt

clean:
	rm -f *.o main_timer libfuncs.a

