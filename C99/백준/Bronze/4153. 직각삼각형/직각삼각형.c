#include <stdio.h>

int main(void){
    
    while(1){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if(a == 0 && b == 0 && c == 0){
            break;
        }

        int sq_a = a * a;
        int sq_b = b * b;
        int sq_c = c * c;

        if(sq_a + sq_b == sq_c || sq_a + sq_c == sq_b || sq_b + sq_c == sq_a){
            printf("right\n");
        } else {
            printf("wrong\n");
        }
    }
}