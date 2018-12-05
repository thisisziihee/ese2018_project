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
#define SZ_BUFFER 30

void set_timer(); void stop_timer(); void restart_timer();
void timer(); int get_time();
int createTimer(time_t* timerID, int sec, int msec);

struct sigevent te; struct itimerspec its; struct sigaction sa;
struct timeval curr; time_t timerID; time_t now; struct tm *t;
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


void make_ramyeon()
{
  printf("원하는 라면의 이름을 입력하세요.\n");
  system("cat example.json | jq '.shin'");
  printf("라면 타이머를 입력해주세요.\n");
  int data = getchar();
  createTimer(&timerID,data,0);
  //printf("shin ramyeon의 가장 맛있게 끓이기 위한 %d초 타이머를 시작하겠습니다.\n",ramyeon_time);
}


void set_timer()
{
  printf(" 타이머 시간을 설정하세요 : ");
  scanf("%d",&mysec);
  createTimer(&timerID, mysec, 0);
  myVal = get_time();
  return;
}

void delete_timer()
{
  if ( timerID == 0 )
  {
    printf(" 현재 설정된 타이머가 없습니다.\n");
    return;
  }
  else
  {
    printf(" 타이머를 강제로 종료합니다.\n");
    timer_delete(&timerID);
    exit(0);
  }
}


void stop_timer()
{
  if ( timerID == 0 ) {
    printf(" 현재 설정된 타이머가 없습니다.\n");
    return;
  }
  else
  {
    timer_delete(&timerID);
    elapse_time = get_time() - myVal;
    time_remaining = mysec - elapse_time;
    printf(" 타이머를 잠시 중단합니다. %d 초 남았습니다. \n", (int)time_remaining);
    return;
  }
}

void resume_timer()
{

  if ( timerID == 0 ){
    printf(" 현재 대기 중인 타이머가 없습니다.\n");
    return;
  }
  else {
    printf(" %d 초 타이머를 다시 시작합니다.\n",time_remaining);
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

int createTimer( time_t* timerID, int sec, int msec)
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
  timer_create(CLOCK_REALTIME, &te,timerID);

  its.it_interval.tv_sec = sec;
  its.it_interval.tv_nsec = 0;
  its.it_value.tv_sec = sec;
  its.it_value.tv_nsec = msec;
  timer_settime(&timerID, 0, &its, NULL);
  return 0;
}

int main()
{
  system("clear");
  printf(" < D : DELETE, S : SET, T : STOP, R : RESUME, M : RAMYEON >\n  원하는 모드를 선택하세요. \n ");
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
      case 'M' :
        make_ramyeon(); break;
      default :	break;
    }
  }
  return 0;
}



