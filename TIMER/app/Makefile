DIR1=../lib
DIR2=../include

main_timer: main_timer.o
	gcc main_timer.o -o main_timer -L$(DIR1) -lfuncs -lrt

main_timer.o: main_timer.c
	gcc -c main_timer.c -I$(DIR2) -o main_timer.o 

clean:
	rm -f main_timer.o main_timer

