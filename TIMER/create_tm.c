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

int createTimer( timer_t* timerID, int sec, int msec)
{
  int sigNo = SIGRTMIN;
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = timerr;
  sigemptyset(&sa.sa_mask);

  if (sigaction(sigNo, &sa, NULL) == -1)
  {
    printf("sigaction error\n");
    return -1;
  }

  te.sigev_notify = SIGEV_SIGNAL;
  te.sigev_signo = sigNo;
  te.sigev_value.sival_ptr = timerID;
  timer_create(CLOCK_REALTIME, &te, timerID);

  its.it_interval.tv_sec = sec;
  its.it_interval.tv_nsec = 0;
  its.it_value.tv_sec = sec;
  its.it_value.tv_nsec = msec;
  timer_settime(*timerID, 0, &its, NULL);
  return 0;
}
