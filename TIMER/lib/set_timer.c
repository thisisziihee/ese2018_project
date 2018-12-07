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
void set_timer()
{
  printf(" 타이머 시간을 설정하세요 : ");
  scanf("%d",&mysec);
  createTimer(&_timerID, 1, 0);
  return;
}
