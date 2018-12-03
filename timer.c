#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void set_timer();
void stop_timer();
void restart_timer();
void timer();
int get_time();
int createTimer(timer_t *imerID, int sec, int msec);

struct sigevent te;
struct itimerspec its;
struct sigaction sa;
struct timeval curr;
time_t timerID;
time_t now; struct tm *t;
int mysec; int myVal, time_remaining, elapse_time;

int get_time()
{
  time(&now);
  t = localtime(&now);
  int hour = t->tm_hour;
  int min = t->tm_min;
  int sec = t->tm_sec;
  int val = min*60 + sec;
  return val;
}

void set_timer()
{
  printf(" 타이머 시간을 설정하세요 : ");
  scanf("%d",&mysec);
  createTimer(&timerID,mysec,0);
  system("date");
  myVal = get_time();
  return;
}

void delete_timer()
{
  if ( timerID == 0 )
  {
    printf("현재 설정된 타이머가 없습니다.\n");
    return;
  }
  else
  {
    printf("타이머를 강제로 종료합니다.\n");
    timer_delete(timerID);
    exit(0);
  }
}


void stop_timer()
{
  printf(" 타이머를 잠시 중단합니다.\n");
  timer_delete(timerID);
  system("date");
  elapse_time = get_time() - myVal;
  time_remaining = mysec - elapse_time;
  printf("%d left\n", time_remaining);
  return;
}

void resume_timer()
{

  if ( timerID == 0 ){
    printf("현재 대기 중인 타이머가 없습니다.\n");
    return;
  }
  else {
    printf(" 타이머를 다시 시작합니다.\n");
    system("date");
    createTimer(&timerID, time_remaining, 0);
    return;
  }
}

void timer()
{
  system("date");
  printf(" 타이머가 종료되었습니다.\n");
  exit(0);
}

int createTimer( timer_t *timerID, int sec, int msec)
{

  int sigNo = SIGRTMIN;
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
  printf("its.it_value.tv_sec : %d\n", its.it_value.tv_sec);
  printf("its.it_vlaue.tv_nsec : %d\n",its.it_value.tv_nsec);

  timer_settime(*timerID, 0, &its, NULL);
  return 0;
}

int main()
{
  printf(" < D : DELETE, S : SET, T : STOP, R : RESUME >\n  원하는 모드를 선택하세요. \n ");
  int data;
  while(1)
  {
    data = getchar();
    switch(data)
    {
      case 'D':
        delete_timer(); break;
      case 'S' :
        set_timer(); break;
      case 'T' :
        stop_timer(); break;
      case 'R' :
        resume_timer(); break;
      default :	break;
    }
  }
}



