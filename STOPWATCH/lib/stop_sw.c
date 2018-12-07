
#include "variable.h"

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

void stop_stopwatch() // 스탑워치 중단
{
    if(time_flag){
        time_flag=0;
        timer_delete(_timerID);
        printf("s:시작, f:리셋, o:랩타임 저장, x:종료\n");
    }else
        printf("이미 중단되었습니다.\n");
    return;
}

