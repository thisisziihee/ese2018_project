DIR=STOPWATCH TIMER
S_I=./STOPWATCH/include
T_I=./TIMER/include
S_L=./STOPWATCH/lib
T_L=./TIMER/lib
CC=gcc
CFLAGS=-g -Wall

.PHONY: all app clean

all:
	@for d in $(DIR);\
	do\
		$(MAKE) -C $$d;\
	done

app: main.c $(S_L)/libfunc_sw.a $(T_L)/libfuncs.a
	$(CC) $(CFLAGS) -o app main.c -L$(S_L) -lfunc_sw -L$(T_L) -lfuncs \
	-I$(S_I) -I$(T_I) -lrt -lm


clean:
	@for d in $(DIR);\
	do\
		$(MAKE) -C $$d clean;\
	done
	rm -f *.o app
