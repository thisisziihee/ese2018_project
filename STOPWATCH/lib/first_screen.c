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

void first_screen()
{
    system("clear"); // 화면 clear
    printf("< stopwatch >\n");
    printf("\n%d\n",time_cnt);
    printf("\ns:시작, d:중단, e:랩, o:랩타임 저장, x:종료\n");
    printf("---------------------------------------------\n");
    return;
}

