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

int main()
{
  system("clear");
  printf(" < D : DELETE, S : SET, T : STOP, R : RESUME, L : Labtime >\n  원하는 모드를 선택하세요. \n ");
  int data;
  while(1) {
    data = getchar();
    switch(data) {
      case 'D':
        delete_timer(); break;
      case 'S' :
        set_timer(); break;
      case 'T' :
        stop_timer(); break;
      case 'R' :
        resume_timer(); break;
      case 'L' :
        labtime(); break;
      default :	break;
    }
  }
  return 0;
}
