#include <stdio.h>
#include <stdlib.h>

int compare(const int *a, const int *b) {
    return *a - *b;
}

int main() {
    int N;
    scanf("%d", &N);

    int S[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }

    qsort(S, N, sizeof(int), compare);//오름차순 

    int target = 1;
    for (int i = 0; i < N; i++) {
        if (S[i] > target) {//가장 작은 자연수O
            break; 
        }
        target += S[i];
    }

    printf("%d\n", target);
    return 0;
}