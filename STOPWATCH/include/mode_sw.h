#ifndef MODESW_H
#define MODESW_H

#define SZ 256

timer_t _timerID;
int time_cnt;
char command;
int lab[SZ];
int lab_idx;
int time_flag;

struct sigevent te;  
struct itimerspec its;  
struct sigaction sa;  

int stopwatch_mode(void);

void start_stopwatch(void);
void reset_stopwatch(void);
void stop_stopwatch(void);
void save_stopwatch(void);
void labtime_stopwatch(void);
void exit_stopwatch(void); 
int createTimer( timer_t *timerID, int sec, int msec );
//int timer_delete(timer_t timerid);

#endif


