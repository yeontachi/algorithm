#include <stdio.h>
#include <math.h>

int main(void){
    int D, H, W;
    scanf("%d %d %d", &D, &H, &W);

    double x_square = (double)(D*D) / (double)(H*H + W*W);
    double x = sqrt(x_square);

    printf("%d %d\n", (int)(H*x), (int)(W*x));
    return 0;
}
