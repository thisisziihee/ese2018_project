#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"screen_sw.h"

void reset_stopwatch() //  스탑워치 초기화
{
    time_cnt=0;
    lab_idx=0;
    timer_delete(_timerID);
    memset(lab,0,SZ*sizeof(int));
    first_screen();
    return;
}

