#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void first_screen(void);
void start_stopwatch(void);
void reset_stopwatch(void);
void save_stopwatch(void);
int createTimer( timer_t *timerID, int sec, int msec );

timer_t _timerID;
int time_cnt=0;
char command;
int lab[100];
int lab_idx=0;

void first_screen()
{
    system("clear"); // 화면 clear
    printf("<스탑워치>\n");
    printf("\n%d\n",time_cnt);
    printf("\ns:실행, d:중단, e:랩 \n");
    printf("-------------------------\n");
    return;
}
void start_stopwatch() // 스탑워치 시작
{
    createTimer(&_timerID, 1 , 0);
    return;
}
void stop_stopwatch() // 스탑워치 중단
{
    timer_delete(_timerID);
    printf("s:시작, f:리셋, o:랩타임 저장\n");
    return;
}
void reset_stopwatch() //  스탑워치 초기화
{
    time_cnt=0;
    lab_idx=0;
    timer_delete(_timerID);
    memset(lab,0,100*sizeof(int));
    first_screen();
    return;
}
void save_stopwatch() // 스탑워치 저장
{
    //int num;
    //printf("저장할 lab number: ");
}

// 타이머 주기에 따라 호출될 타이머
void timer() // 1초 마다 clear시키면서 화면에 timer를 띄운다.
{
    int i=0;
    system("clear"); // 화면 clear
    printf("<스탑워치>\n");
    printf("\n%d\n",++time_cnt);
    printf("\nd:중단, e:랩 \n");
    printf("-------------------------\n");
    if(lab_idx) // lab타임이 있다면
    {
        for(i=0;i<lab_idx;i++)
            printf("lab %d : %d \n",lab_idx,lab[lab_idx]);
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

int main(void)
{
    
    // 타이머를 만든다
    // 매개변수 1 : 타이머 변수
    // 매개변수 2 : second
    // 매개변수 3 : ms

    first_screen(); // 스탑워치 첫 화면

    while(1)
    {
        command=getchar();
        // s: 실행, d:중단, f: 리셋, e:랩타임 실행, o:랩타임 저장
        switch(command){
            case 's': start_stopwatch(); break; // timer실행
            case 'd': stop_stopwatch(); break; // timer중단
            case 'f': reset_stopwatch(); break;
            //case 'e': lab[lab_idx]=time_cnt; lab_idx++; break;
            //case 'o': save_stopwatch(); break;
           // default: printf("error\n");
        }
    }
    
    
}



