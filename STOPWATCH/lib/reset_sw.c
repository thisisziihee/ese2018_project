
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
#include "mode_sw.h"
#include "screen_sw.h"


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

