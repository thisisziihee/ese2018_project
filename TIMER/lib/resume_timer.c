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
void resume_timer()
{

  if ( _ttimerID == 0 || stop_flag == 0){
    printf(" 현재 대기 중인 타이머가 없습니다.\n");
    return;
  }
  else {
    stop_flag=0;
    printf(" %d 초 타이머를 다시 시작합니다.\n",mysec);
    createTimer(&_ttimerID, 1, 0);
    return;
  }
}
