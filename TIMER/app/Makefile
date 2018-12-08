CC=gcc
CFLAGS=-g -Wall
L_DIR=../lib
H_DIR=../include
EXEC=main_timer

$(EXEC): main_timer.c $(L_DIR)/libfuncs.a
	$(CC) $(CFALGS) -o $(EXEC) main_timer.c -L$(L_DIR) -lfuncs -I$(H_DIR) -lrt

clean:
	rm -f $(EXEC)

