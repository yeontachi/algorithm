#include <stdio.h>
#include <time.h>

int main(void){
    time_t timer;
    struct tm *t;

    // 현재 시간 가져오기
    timer = time(NULL);

    timer += (9 * 60 * 60); // UTC+9 시간으로 변환

    // 초 단위 시간을 연, 월, 일 구조체로 변환
    t = gmtime(&timer);

    // YYYY-MM-DD 형식으로 출력
    printf("%04d-%02d-%02d \n",t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    return 0;
}