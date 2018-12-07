#ifndef MODE_SW_H
#define MODE_SW_H


void start_stopwatch(void);
void reset_stopwatch(void);
void save_stopwatch(void);
void labtime_stopwatch(void);
void exit_stopwatch(void); 
int createTimer( timer_t *timerID, int sec, int msec );

#endif


