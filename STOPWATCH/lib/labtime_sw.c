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


void labtime_stopwatch() // 랩타임 저장
{
    lab[lab_idx++]=time_cnt;
    printf("lab %d : %d \n",lab_idx,lab[lab_idx-1]);

    return;
}

