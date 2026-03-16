#include <stdio.h>

typedef struct {
    long long x;
    long long y;
} Point;

long long absolute(long long num){
    if(num > 0) return num;
    return -num;
}

int main(void){
    int N;
    scanf("%d", &N);

    Point points[N];

    for(int i = 0; i < N; i++){
        scanf("%lld %lld", &points[i].x, &points[i].y);
    }

    long long total_area = 0;

    for(int i=0; i<N; ++i){
        int next = (i + 1) % N; // 마지막 점은 다시 첫 번째 점과 연결되어야 함

        // 외적
        total_area += (points[i].x * points[next].y) - (points[next].x * points[i].y);
    }

    printf("%.1f\n", absolute(total_area) / 2.0);

    return 0;
}