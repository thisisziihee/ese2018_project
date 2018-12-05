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

void first_screen(void);
int save_screen(void);
void start_stopwatch(void);
void reset_stopwatch(void);
void save_stopwatch(void);
void labtime_stopwatch(void);
int createTimer( timer_t *timerID, int sec, int msec );

timer_t _timerID;
int time_cnt=0;
char command;
int lab[100];
int lab_idx=0;

void first_screen()
{
    system("clear"); // 화면 clear
    printf("< stopwatch >\n");
    printf("\n%d\n",time_cnt);
    printf("\ns:실행, d:중단, e:랩 \n");
    printf("-------------------------\n");
    return;
}

int save_screen()
{
    system("clear");
    printf("< save mode >\n");
    if(lab_idx) // lab타임이 있다면
    {
        system("clear");
        for(int i=0;i<lab_idx;i++)
            printf("lab %d : %d \n",i+1,lab[i]);
	return 0;
    }
    else // lab타임이 없다면
    {
        char c;
        printf("랩타임이 존재하지 않습니다.\n");
        printf("c:돌아가기\n");
        scanf("%c",&c);
        if(c=='c'){
            first_screen();
            return -1;
        }
    }


}


void start_stopwatch() // 스탑워치 시작
{
    createTimer(&_timerID, 1 , 0);
    return;
}

void stop_stopwatch() // 스탑워치 중단
{
    timer_delete(_timerID);
    printf("s:시작, f:리셋, o:랩타임 저장\n");
    return;
}
void reset_stopwatch() //  스탑워치 초기화
{
    time_cnt=0;
    lab_idx=0;
    timer_delete(_timerID);
    memset(lab,0,100*sizeof(int));
    first_screen();
    return;
}

void labtime_stopwatch() // 랩타임 저장
{
    lab[lab_idx++]=time_cnt;
//    printf("lab[lab_idx]=%d time_cnt=%d",lab[lab_idx-1],time_cnt);
}
void save_stopwatch() // 스탑워치 저장
{

    if(save_screen()==-1){ // labtime이 없음
	first_screen();
	return;
    }

    int num;
    printf("저장할 lab number: ");
    while(1) {
	scanf("%d",&num);
	if( num<1 || num>lab_idx) //num이 1보다 작거나 lab_idx보다$
	{
            printf("\n올바른 lab number를 쓰시오.\n");
	    printf("저장할 lab number: ");
	}
	else
	    break;
    }
    char name[1024];
    printf("저장할 이름: ");
    scanf("%s",name);
//    printf("%s",name);
    int fd;
    fd=open("labtime.txt", O_RDWR | O_CREAT | O_APPEND , 0666);
    if( fd == -1 ) // file open error
    {
	perror("open");
	exit(0);
    } else {
//	char buffer[1];
	char buf1[1]={'-'};
        char buf2[1]={'\n'};
        char t[256];
	memset(t,0,0);
	sprintf(t,"%d",lab[num-1]);
        int n=log10(lab[num-1])+1;

	write(fd,name,strlen(name)); // name
        write(fd,buf1,1); // name -
        write(fd,t,4*(n/4)+(n%4)); // time의 자리수만큼만 쓴 $
        write(fd,buf2,1); //name-time\n

//	printf("%s strlen(name):%ld\n",name,strlen(name));
//	printf("lab[num-1]:%d, 4--:%d\n",lab[num-1],4*(n/4)+(n%4));
    }
    close(fd);

    
    return;
}

// 타이머 주기에 따라 호출될 타이머
void timer() // 1초 마다 clear시키면서 화면에 timer를 띄운다.
{
    int i=0;
    system("clear"); // 화면 clear
    printf("<스탑워치>\n");
    printf("\n%d\n",++time_cnt);
    printf("\nd:중단, e:랩 \n");
    printf("-------------------------\n");
    if(lab_idx) // lab타임이 있다면
    {
        for(i=0;i<lab_idx;i++)
            printf("lab %d : %d \n",i+1,lab[i]);
    }
}
int createTimer( timer_t *timerID, int sec, int msec )  
{  
    struct sigevent         te;  
    struct itimerspec       its;  
    struct sigaction        sa;  
    int                     sigNo = SIGRTMIN;  
   
    /* Set up signal handler. */  
    sa.sa_flags = SA_SIGINFO;  
    sa.sa_sigaction = timer;     // 타이머 호출시 호출할 함수 
    sigemptyset(&sa.sa_mask);  
  
    if (sigaction(sigNo, &sa, NULL) == -1)  
    {  
        printf("sigaction error\n");
        return -1;  
    }  
    /* Set and enable alarm */  
    te.sigev_notify = SIGEV_SIGNAL;  
    te.sigev_signo = sigNo;  
    te.sigev_value.sival_ptr = timerID;  
    timer_create(CLOCK_REALTIME, &te, timerID);  
   
    its.it_interval.tv_sec = sec;
    its.it_interval.tv_nsec = msec * 1000000;  
    its.it_value.tv_sec = sec;
    
    its.it_value.tv_nsec = msec * 1000000;
    timer_settime(*timerID, 0, &its, NULL);  
   
    return 0;  
}

int main(void)
{
    
    // 타이머를 만든다
    // 매개변수 1 : 타이머 변수
    // 매개변수 2 : second
    // 매개변수 3 : ms

    first_screen(); // 스탑워치 첫 화면

    while(1)
    {
        command=getchar();
        // s: 실행, d:중단, f: 리셋, e:랩타임 실행, o:랩타임 저장
        switch(command){
            case 's': start_stopwatch(); break; // timer실행
            case 'd': stop_stopwatch(); break; // timer중단
            case 'f': reset_stopwatch(); break; // timer reset
            case 'e': labtime_stopwatch(); break; // timer labtime저장
            case 'o': save_stopwatch(); break; // save stopwatch
           // default: printf("error\n");
        }
    }
    
    
}



