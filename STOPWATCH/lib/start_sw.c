#include<time.h>
#include<stdio.h>

void start_stopwatch() // 스탑워치 시작
{
    if(time_flag){
        printf("이미 실행 중입니다.\n");
    }
    else
    {
        createTimer(&_timerID, 1 , 0);
        time_flag=1;
    }
    return;
}

