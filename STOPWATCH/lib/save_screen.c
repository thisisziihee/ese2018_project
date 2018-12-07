#include <stdlib.h>
#include <stdio.h>
#include "screen_sw.h"


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

