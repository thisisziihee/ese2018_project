AR=ar
CC=gcc
CFLAGS=-g -Wall
LIB=libfunc_sw.a
DIR=../include/
OBJS=createTimer_sw.o first_screen.o main_sw.o save_screen.o start_sw.o exit_sw.o labtime_sw.o reset_sw.o save_sw.o stop_sw.o

$(LIB): $(OBJS)
	$(AR) rv $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(DIR) -o $@

clean:
	rm -f $(OBJS) $(LIB)

