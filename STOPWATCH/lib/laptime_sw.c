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


void laptime_stopwatch() // 랩타임 저장
{
    lap[lap_idx++]=time_cnt;
    printf("lap %d : %d \n",lap_idx,lap[lap_idx-1]);

    return;
}

