#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "varitimer.h"
void stop_timer()
{
  if ( _timerID == 0 ) {
    printf(" 현재 설정된 타이머가 없습니다.\n");
    return;
  }
  else
  {
    stop_flag = 1;
    timer_delete(_timerID);
    printf(" 타이머를 잠시 중단합니다. %d 초 남았습니다. \n", (int)mysec);
    return;
  }
}

