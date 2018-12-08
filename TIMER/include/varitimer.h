#ifndef VARITIMER_H
#define VARITIMER_H

void labtime();
void set_timer(); void stop_timer(); void resume_timer();
void timerr(); int get_time(); void delete_timer();
int createmyTimer(timer_t* ttimerID, int sec, int msec);
int timer_mode();

struct sigevent tte; struct itimerspec tits; struct sigaction tsa;
timer_t _ttimerID;
int mysec; int cnt; int stop_flag;

struct labtime {
  char name[10];
  char time[3];
};

struct labtime ramen[100];

#endif
