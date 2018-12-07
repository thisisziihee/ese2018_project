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

void labtime();
void set_timer(); void stop_timer(); void restart_timer();
void timerr(); int get_time();
int createTimer(timer_t* timerID, int sec, int msec);

struct sigevent te; struct itimerspec its; struct sigaction sa;
struct timeval curr; timer_t _timerID; 
int mysec; int cnt;

struct labtime {
  char name[10];
  char time[3];
};

struct labtime ramen[100];

void labtime()
{
  FILE *f = fopen("/home/jihee/sw_jihee/project/STOPWATCH/labtime.txt", "r");
  char buffer[20]; cnt=0;

  while( fgets(buffer,sizeof(buffer),f) !=0) {
    fputs(buffer, stdout);
    char* ftr; char* str; int idx;
    ftr = strtok(buffer, " ");
    strcpy(ramen[cnt].name,ftr);
    ftr = strtok( NULL, "\n");
    strcpy(ramen[cnt].time,ftr);
    cnt++;
  }
  fclose(f);
  printf(" 다음 중 원하는 라면의 이름을 입력하세요.\n");
  char data[10]; scanf("%s",data); int flag =0;
  for(int i=0;i<cnt;i++) {
    if(strcmp(data, ramen[i].name) == 0) {
      flag=1;
      printf(" %s 의 %s 초 타이머를 시작합니다.\n",ramen[i].name, ramen[i].time);
      mysec = atoi(ramen[i].time);
      createTimer(&_timerID,1,0);
    }
  }
  if (flag == 0) {
    printf(" 원하는 라면의 타이머가 없습니다. \n");
    exit(0);
  }
  return;
}


void set_timer()
{
  printf(" 타이머 시간을 설정하세요 : ");
  scanf("%d",&mysec);
  createTimer(&_timerID, 1, 0);
  return;
}

void delete_timer()
{
  if ( _timerID == 0 )
  {
    printf(" 현재 설정된 타이머가 없습니다.\n");
    return;
  }
  else
  {
    printf(" 타이머를 강제로 종료합니다.\n");
    timer_delete(&_timerID);
    exit(0);
  }
}


void stop_timer()
{
  if ( _timerID == 0 ) {
    printf(" 현재 설정된 타이머가 없습니다.\n");
    return;
  }
  else
  {
    timer_delete(_timerID);
    printf(" 타이머를 잠시 중단합니다. %d 초 남았습니다. \n", (int)mysec);
    return;
  }
}

void resume_timer()
{

  if ( _timerID == 0 ){
    printf(" 현재 대기 중인 타이머가 없습니다.\n");
    return;
  }
  else {
    printf(" %d 초 타이머를 다시 시작합니다.\n",mysec);
    createTimer(&_timerID, 1, 0);
    return;
  }
}

void timerr()
{
  mysec--;
  printf(" %d초 남았습니다.\n",mysec);
  if( mysec == 0 ){
    printf(" 타이머가 종료되었습니다.\n");
    exit(0);
  }
}

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

int main()
{
  system("clear");
  printf(" < D : DELETE, S : SET, T : STOP, R : RESUME, L : Labtime >\n  원하는 모드를 선택하세요. \n ");
  int data;
  while(1) {
    data = getchar();
    switch(data) {
      case 'D':
        delete_timer(); break;
      case 'S' :
        set_timer(); break;
      case 'T' :
        stop_timer(); break;
      case 'R' :
        resume_timer(); break;
      case 'L' :
        labtime(); break;
      default :	break;
    }
  }
  return 0;
}



