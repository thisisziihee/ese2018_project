#include<stdio.h>

void labtime_stopwatch() // 랩타임 저장
{
    lab[lab_idx++]=time_cnt;
    printf("lab %d : %d \n",lab_idx,lab[lab_idx-1]);

    return;
}

