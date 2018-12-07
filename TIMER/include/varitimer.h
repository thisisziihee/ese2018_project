#ifndef VARITIMER_H
#define VARITIMER_H

void labtime();
void set_timer(); void stop_timer(); void restart_timer();
void timerr(); int get_time(); 
int createTimer(timer_t* timerID, int sec, int msec);


struct sigevent te; struct itimerspec its; struct sigaction sa;
 timer_t _timerID; 
int mysec; int cnt; int stop_flag;

struct labtime {
  char name[10];
  char time[3];
};

struct labtime ramen[100];

#endif
