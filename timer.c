#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>
void set_timer();
void stop_timer();
void restart_timer();
void timer();
int createTimer(timer_t *imerID, int sec, int msec);

struct sigevent te;
struct itimerspec its;
struct sigaction sa;

timer_t timerID;
timer_t stoptimer;
int leftsec;



void set_timer()
{
  printf(" 타이머 시간을 설정하세요 : ");
  int mysec;
  scanf("%d",&mysec);
  createTimer(&timerID,mysec,0);
  printf(" %d 초 남았습니다.\n", timer_gettime(timerID, &its));
  return;
}

void stop_timer()
{
  printf(" 타이머를 잠시 중단합니다.\n");
  //현재 남은 시간 받아와서 timr_t stoptimer에 저장
  /*if( timer_delete(timerID) == 0 )
  {
    printf("success\n");
  }*/
  //return;
}

void restart_timer()
{
  printf(" 타이머를 다시 시작합니다.\n");
  // timer_t stoptimer 받아와서 다시 시작
 /* while(1)
  {
    createTimer(&stoptimer,leftsec,0);
  }*/
  return;
}

void timer()
{
  printf(" 타이머가 종료되었습니다.\n");
  exit(0);
}

int createTimer( timer_t *timerID, int sec, int msec)
{

  int sigNo = SIGRTMIN;
  //Handler
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = timer;
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

int main()
{
  printf(" < R : RESET, S : STOP, T : RESTART > 원하는 모드를 선택하세요. \n ");
  int data;
  data = getchar();
  while(1)
  {
    switch(data)
    {
      case 'R' :
        set_timer(); break;
      case 'S' :
        stop_timer(); break;
      case 'T' :
        restart_timer(); break;
      default :	break;
     }
    data=getchar();
  }
}



