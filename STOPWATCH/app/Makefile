CC=gcc
CFLAGS=-g -Wall
L_DIR=../lib/
H_DIR=../include
EXEC=myapp

$(EXEC): main_sw.c $(L_DIR)libfunc_sw.a
	$(CC) $(CFALGS) -o $(EXEC) main_sw.c -L$(L_DIR) -lfunc_sw -I$(H_DIR)

clean:
	rm -f $(EXEC)

