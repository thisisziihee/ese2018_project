#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>
void reset_timer();
void stop_timer();
void restart_timer();
void timer();
int createTimer(timer_t *imerID, int sec, int msec);

int stopflag=0;

void timer() // Timer to be recalled according to the timer interval
{
  printf(" Time's UP!\n");
  exit(0);
}

int createTimer( timer_t *timerID, int sec, int msec)
{
    struct sigevent         te;
    struct itimerspec       its;
    struct sigaction        sa;
    int                     sigNo = SIGRTMIN;

    /* Set up signal handler. */
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = timer;     // 타이머 호출시 호출할 함수
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
    its.it_interval.tv_nsec = msec;
    its.it_value.tv_sec = sec;
    its.it_value.tv_nsec = msec;
    timer_settime(*timerID, 0, &its, NULL);
    return 0;
}

void reset_timer()
{
  printf(" reset timer(unit:sec) : ");
  int mysec;
  scanf("%d",&mysec);
  printf(" you set the %d sec\n",mysec);
  timer_t timerID;
  while( stopflag != 1 )
  {
    createTimer(&timerID,mysec,0);
  }
  return;
}

void stop_timer()
{
  printf(" stop timer\n");
  return;
}

void restart_timer()
{
  printf(" restart timer\n");
  return;
}

int main()
{
  printf(" mode  < R : RESET, S : STOP, T : RESTART >\n ");
  int data;
  printf("Enter the mode you want : ");
  data = getchar();
  while(1)
  {
    switch(data)
    {
      case 'R' :
        reset_timer();
        break;
      case 'S' :
	stopflag = 1;
        stop_timer();
        break;
      case 'T' :
        restart_timer();
        break;
      default :
        printf("Try Again\n");
        break;
     }
  break;
  }
}



