libfuncs.a: *.o
	ar rv $@ *.o

*.o: *.c
	gcc -g -Wall -c -I/home/jihee/sw_jihee/project/TIMER/includ *.c -lrt

clean:
	rm -f *.o
