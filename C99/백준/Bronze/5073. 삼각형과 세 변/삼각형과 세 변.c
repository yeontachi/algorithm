#include <stdio.h>

int main(void){

    while(1){
        int A[3];

        scanf("%d %d %d", &A[0], &A[1], &A[2]);

        if(A[0]==0 && A[1]==0 && A[2]==0){
            break;
        }

        int max=0;
        int max_idx = 0;

        for(int i=0; i<3; ++i){
            if(max <= A[i]){
                max = A[i];
                max_idx = i;
            }
        }

        if(A[max_idx] >= A[(max_idx+1)%3] + A[(max_idx+2)%3]){
            printf("Invalid\n");
        }
        else{
            if(A[0]==A[1] && A[1]==A[2]){
                printf("Equilateral\n");
            }
            else if(A[0]==A[1] || A[1]==A[2] || A[0]==A[2]){
                printf("Isosceles\n");
            }
            else{
                printf("Scalene\n");
            }
        }
    }

    return 0;
}