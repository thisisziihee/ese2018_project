#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "varitimer.h"


int timer_mode()
{

  system("clear");
  printf(" < d : DELETE, s : SET, t : STOP, r : RESUME, l : Laptime >\n  원하는 모드를 선택하세요. \n ");
  int data_timer;
  while(1) {
    data_timer= getchar();
    switch(data_timer) {
      case 'd':
        delete_timer(); break;
      case 's' :
        set_timer(); break;
      case 't' :
        stop_timer(); break;
      case 'r' :
        resume_timer(); break;
      case 'l' :
        laptime(); break;
      default :	break;
    }
  }
  return 0;
}
