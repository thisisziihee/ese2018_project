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
#include "mode_sw.h"
#include "screen_sw.h"

int save_screen()
{
    system("clear"); 
    printf("< save mode >\n\n");
    if(lap_idx) // lap타임이 있다면
    {
        for(int i=0;i<lap_idx;i++)
            printf("lap %d : %d \n",i+1,lap[i]);
        return 0;
    }
    else // lap타임이 없다면
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

