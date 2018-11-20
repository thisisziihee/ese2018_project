#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<unistd.h>

void timer() // Timer to be recalled according to the timer interval
{
  printf("\n**************Time's UP!************\n");
}

int createTimer( timer_t *timerID, int sec, int msec )
{
  struct sigevent te;
  struct itimerspec its;
  struct sigaction sa;
  int sigNo = SIGRTMIN;

  // set up signal handler

/* Set up signal handler. */  
    sa.sa_flags = SA_SIGINFO;  
    sa.sa_sigaction = timer;     // 타이머 호출시 호출할 함수 
    sigemptyset(&sa.sa_mask);  
  
    if (sigaction(sigNo, &sa, NULL) == -1)  
    {  
        printf("sigaction error\n");
        return -1;  
    }  
   
    /* Set and enable alarm */  
    te.sigev_notify = SIGEV_SIGNAL;  
    te.sigev_signo = sigNo;  
    te.sigev_value.sival_ptr = timerID;  
    timer_create(CLOCK_REALTIME, &te, timerID);  
   
    its.it_interval.tv_sec = sec;
    its.it_interval.tv_nsec = msec * 1000000;  
    its.it_value.tv_sec = sec;
    
    its.it_value.tv_nsec = msec * 1000000;
    timer_settime(*timerID, 0, &its, NULL);  
   
    return 0;  
}
 
int main()
{
    timer_t timerID;

    // 타이머를 만든다
    // 매개변수 1 : 타이머 변수
    // 매개변수 2 : second
    // 매개변수 3 : ms

  int i=0;
  for [ i in 5 ]
  {
    read mytime;
    createTimer(&timerID,5, 0);
  }
}

