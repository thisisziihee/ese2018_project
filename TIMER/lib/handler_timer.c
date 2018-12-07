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

void timerr()
{
  mysec--;
  printf(" %d초 남았습니다.\n",mysec);
  if( mysec == 0 ){
    printf(" 타이머가 종료되었습니다.\n");
    exit(0);
  }
}
