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
void labtime()
{
  FILE *f = fopen("/home/jihee/sw_jihee/project/STOPWATCH/labtime.txt", "r");
  char buffer[20]; cnt=0;

  while( fgets(buffer,sizeof(buffer),f) !=0) {
    fputs(buffer, stdout);
    char* ftr;
    ftr = strtok(buffer, " ");
    strcpy(ramen[cnt].name,ftr);
    ftr = strtok( NULL, "\n");
    strcpy(ramen[cnt].time,ftr);
    cnt++;
  }
  fclose(f);
  printf(" 다음 중 원하는 라면의 이름을 입력하세요.\n");
  char data[10]; scanf("%s",data); int flag =0;
  for(int i=0;i<cnt;i++) {
    if(strcmp(data, ramen[i].name) == 0) {
      flag=1;
      printf(" %s 의 %s 초 타이머를 시작합니다.\n",ramen[i].name, ramen[i].time);
      mysec = atoi(ramen[i].time);
      createTimer(&_timerID,1,0);
    }
  }
  if (flag == 0) {
    printf(" 원하는 라면의 타이머가 없습니다. \n");
    exit(0);
  }
  return;
}
