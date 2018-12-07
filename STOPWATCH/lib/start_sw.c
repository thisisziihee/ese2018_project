//#include "variable.h"
#include "mode_sw.h"
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

void start_stopwatch() // 스탑워치 시작
{
    if(time_flag){
        printf("이미 실행 중입니다.\n");
    }
    else
    {
        createTimer(&_timerID, 1 , 0);
        time_flag=1;
    }
    return;
}

