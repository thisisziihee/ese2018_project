#include "screen_sw.h"
//#include "variable.h"

#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#define SZ 256
timer_t _timerID;
static int time_cnt;
static char command;
static int lab[SZ];
static int lab_idx;
static int time_flag;


int save_screen()
{
    system("clear"); 
    printf("< save mode >\n\n");
    if(lab_idx) // lab타임이 있다면
    {
        for(int i=0;i<lab_idx;i++)
            printf("lab %d : %d \n",i+1,lab[i]);
        return 0;
    }
    else // lab타임이 없다면
    {
        char c;
        printf("랩타임이 존재하지 않습니다.\n");
        printf("c:돌아가기\n");
        while(1){
            scanf("%c",&c);
            if(c=='c'){
            first_screen();
            return -1;
            }
        } 
    }
}

