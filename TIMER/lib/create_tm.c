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

int createmyTimer( timer_t* ttimerID, int sec, int msec)
{
  int sigNo = SIGRTMIN;
  tsa.sa_flags = SA_SIGINFO;
  tsa.sa_sigaction = timerr;
  sigemptyset(&tsa.sa_mask);

  if (sigaction(sigNo, &tsa, NULL) == -1)
  {
    printf("sigaction error\n");
    return -1;
  }

  tte.sigev_notify = SIGEV_SIGNAL;
  tte.sigev_signo = sigNo;
  tte.sigev_value.sival_ptr = ttimerID;
  timer_create(CLOCK_REALTIME, &tte, ttimerID);

  tits.it_interval.tv_sec = sec;
  tits.it_interval.tv_nsec = 0;
  tits.it_value.tv_sec = sec;
  tits.it_value.tv_nsec = msec;
  timer_settime(*ttimerID, 0, &tits, NULL);
  return 0;
}
