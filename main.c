#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include "mode_sw.h"
#include "varitimer.h"


int main()
{
  system("clear");
  printf("\n**********************************\n");
  printf("**                              **\n");
  printf("**    S : STOPWATCH T : TIMER   **\n");
  printf("**                              **\n");
  printf("**   원하는 모드를 선택하세요   **\n");
  printf("**                              **\n");
  printf("**********************************\n");

  char mode_data;
  while(1) {
    mode_data = getchar();
    switch (mode_data) {
      case 'T' :
        timer_mode(); break;
      case 'S' :
        stopwatch_mode(); break;
      default : break;
    }
  }


  return 0;
}
