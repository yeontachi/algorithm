#include <stdio.h>
#include <math.h>

// 꼭짓점 수 - 모서리 수 + 면의 수 = 2
// 면의 수 = 2 - 꼭짓점 수 + 모서리 수
int main(void){
    int T;
    scanf("%d", &T);

    while(T--){
        int V, E;
        scanf("%d %d", &V, &E);

        int F = 2 - V + E;
        printf("%d\n", F);
    }
}