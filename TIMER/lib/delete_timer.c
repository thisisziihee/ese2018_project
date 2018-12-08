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

void delete_timer()
{
  if ( _ttimerID == 0 )
  {
    printf(" 현재 설정된 타이머가 없습니다.\n");
    return;
  }
  else
  {
    printf(" 타이머를 강제로 종료합니다.\n");
    timer_delete(&_ttimerID);
    exit(0);
  }
}
