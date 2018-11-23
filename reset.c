#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void timer_handler (int signum)
{
  printf( " Time's UP!\n");
}

int main ()
{
        struct sigaction sa;
        struct itimerval timer;   //타이머가 경과되는 때 정하기 위해서 사용

        memset (&sa, 0, sizeof (sa));

	// signum번호를 가지는 시그널이 발생했을 때 실행된 함수를 설치
        sa.sa_handler = &timer_handler;
        sigaction (SIGALRM, &sa, NULL);

	// 첫 번째 타이머 인터럽트 간격. 만일 0이면, 알람은 불가능.
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;

	// 연속적인 타이머 인터럽트들 사이의 간격. 만일 0이면, alarm은 오직 한 번만 보내질 것.
        timer.it_interval.tv_sec = 3;
        timer.it_interval.tv_usec = 0;

        // 알람을 설정하기 위해서 주요한 방법.
        getitimer (ITIMER_REAL, &timer);

        /* Do busy work.  */
        while (1);
}
