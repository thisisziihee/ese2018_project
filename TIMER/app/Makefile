main_timer: main_timer.o
	gcc main_timer.o -o main_timer -L/home/jihee/sw_jihee/project/TIMER/lib -lfuncs -lrt

main_timer.o: main_timer.c
	gcc -c main_timer.c -I/home/jihee/sw_jihee/project/TIMER/includ -o main_timer.o 

clean:
	rm -f main_timer.o main_timer

