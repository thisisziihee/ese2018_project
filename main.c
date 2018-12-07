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

  int data;
  while(1) {
    data = getchar();
    switch (data) {
      case 'T' :
        timer_mode(); break;
      case 'S' :
        stopwatch_mode(); break;
      default : break;
    }
  }


  return 0;
}
