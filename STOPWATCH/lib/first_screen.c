#include <stdlib.h>
#include <stdio.h>

void first_screen()
{
    system("clear"); // 화면 clear
    printf("< stopwatch >\n");
    printf("\n%d\n",time_cnt);
    printf("\ns:시작, d:중단, e:랩, x:종료\n");
    printf("-------------------------\n");
    return;
}

