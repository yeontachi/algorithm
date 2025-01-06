#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int main(void){
    int N;
    scanf("%d", &N);

    int *p=(int*)malloc(N*sizeof(int));

    for(int i=0; i<N; i++)
        scanf("%d", &p[i]);

    
    qsort(p, N, sizeof(int), comp);

    int result=0;

    for(int i=0; i<N; i++){
        if((i+1)%3 != 0){//세번째 항목마다 공짜
            result+=p[i];
        }
    }

    free(p);

    printf("%d\n", result);

    return 0;
}