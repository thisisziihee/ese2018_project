#include "variable.h"
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


// 타이머 주기에 따라 호출될 타이머
void timer() // 1초 마다 clear시키면서 화면에 timer를 띄운다.
{
    int i=0;
    system("clear"); // 화면 clear
    printf("< stopwatch >\n");
    printf("\n%d\n",++time_cnt);
    printf("\nd:중단, e:랩, x:종료\n");
    printf("-------------------------\n");
    if(lab_idx) // lab타임이 있다면
    {
        for(i=0;i<lab_idx;i++)
            printf("lab %d : %d \n",i+1,lab[i]);
    }
}
int createTimer( timer_t *timerID, int sec, int msec )  
{  
    struct sigevent         te;  
    struct itimerspec       its;  
    struct sigaction        sa;  
    int                     sigNo = SIGRTMIN;  

    /* Set up signal handler. */  
    sa.sa_flags = SA_SIGINFO;  
    sa.sa_sigaction = timer;     // 타이머 호출시 호출할 함수 
  
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

