#ifndef VARIABLE_H
#define VARIABLE_H


#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#define SZ 256
timer_t _timerID;
static int time_cnt=0;
static char command;
static int lab[SZ];
static int lab_idx=0;
static int time_flag=0;

#endif



