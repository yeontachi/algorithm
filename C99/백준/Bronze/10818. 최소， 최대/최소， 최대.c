#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N); // 정수 개수

    int max = -1000001;
    int min = 1000001;

    for(int i=0; i<N; ++i){
        int num=0;
        scanf("%d", &num); // N개의 정수 입력

        if(num > max){
            max = num;
        }
        if(num < min){
            min = num;
        }

    }
    printf("%d %d\n", min, max);
    return 0;
}