
#include"screen_sw.h"
//#include"variable.h"
#include"mode_sw.h"

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
static int time_cnt;
static char command;
static int lab[SZ];
static int lab_idx;
static int time_flag;

//int timer_delete(timer_t timerid);

void reset_stopwatch() //  스탑워치 초기화
{
    time_cnt=0;
    lab_idx=0;
    timer_delete(_timerID);
    memset(lab,0,SZ*sizeof(int));
    first_screen();
    return;
}

