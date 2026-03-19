#include <stdio.h>

int main(void){
    int N, W, H;
    scanf("%d %d %d", &N, &W, &H);

    int max_len = W*W + H*H;

    while(N--){
        int len;
        scanf("%d", &len);

        if(len*len <= max_len){
            printf("DA\n");
        } else {
            printf("NE\n");
        }
    }
}