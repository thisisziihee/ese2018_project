#include"screen_sw.h"
#include<stdio.h>
#include<stdlib.h>
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


void save_stopwatch() // 스탑워치 저장
{

    if(save_screen()==-1){ // labtime이 없음
        system("clear");
        first_screen();
        command = 'd';
        return;
    }
    int num;
    printf("저장할 lab number: ");
    while(1) {
        scanf("%d",&num);
        if( num<1 || num>lab_idx) //num이 1보다 작거나 lab_idx보다$
        {
            printf("올바른 lab number를 쓰시오.\n");
            printf("저장할 lab number: ");
        }
        else
            break;
    }
    char name[SZ];
    printf("저장할 이름: ");
    scanf("%s",name);
    int fd;
    fd=open("labtime.txt", O_RDWR | O_CREAT | O_APPEND , 0666);
    if( fd == -1 ) // file open error
    {
        perror("open");
        exit(0);
    } else {
        char buf1[1]={' '};
        char buf2[1]={'\n'};
        char t[256];
        memset(t,0,0);
        sprintf(t,"%d",lab[num-1]);
        int n=log10(lab[num-1])+1;

        write(fd,name,strlen(name)); // name
        write(fd,buf1,1); // name -
        write(fd,t,4*(n/4)+(n%4)); // time의 자리수만큼만 쓴 $
        write(fd,buf2,1); //name-time\n

        printf("저장완료!\n");
   }
    close(fd);
    char c;
    printf("c:돌아가기\n");
    while(1){
        scanf("%c",&c);
        if(c=='c'){
            first_screen();
            break;
        }
    }

    
    return;
}

