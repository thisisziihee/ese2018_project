//#include "variable.h"
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

void first_screen()
{
    system("clear"); // 화면 clear
    printf("< stopwatch >\n");
    printf("\n%d\n",time_cnt);
    printf("\ns:시작, d:중단, e:랩, x:종료\n");
    printf("-------------------------\n");
    return;
}

