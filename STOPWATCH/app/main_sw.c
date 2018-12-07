#include "screen_sw.h"
#include "mode_sw.h"
//#include "main_sw.h"
#include "variable.h"

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
        // s: 실행, d:중단, f: 리셋, e:랩타임 실행, o:랩타임 저장 x:$
        switch(command){
            case 's': start_stopwatch(); break; // timer실행
            case 'd': stop_stopwatch(); break; // timer중단
            case 'f': reset_stopwatch(); break; // timer reset
            case 'e': labtime_stopwatch(); break; // timer labtime저$
            case 'x': exit_stopwatch(); break; // tiemr 종료
            case 'o': save_stopwatch(); break; // save stopwatch
            default: break;
        }
    }
    return 0;
}

