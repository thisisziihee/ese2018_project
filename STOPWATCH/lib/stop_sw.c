#include<stdio.h>
#include<time.h>

void stop_stopwatch() // 스탑워치 중단
{
    if(time_flag){
        time_flag=0;
        timer_delete(_timerID);
        printf("s:시작, f:리셋, o:랩타임 저장, x:종료\n");
    }else
        printf("이미 중단되었습니다.\n");
    return;
}

