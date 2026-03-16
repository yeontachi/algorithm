#include <stdio.h>

int main() {
    int A[3];

    scanf("%d %d %d", &A[0], &A[1], &A[2]);

    int max_idx = 0;
    int max_value = 0;

    for(int i=0; i<3; ++i){
        if(max_value <= A[i]){
            max_value = A[i];
            max_idx = i;
        }
    }

    int sum = A[0] + A[1] + A[2];

    while(1){
        if( A[max_idx] < A[(max_idx + 1) % 3] + A[(max_idx + 2) % 3]){
            printf("%d", sum);
            break;
        }
        else{
            sum--;
            A[max_idx]--;
        }
    }
}