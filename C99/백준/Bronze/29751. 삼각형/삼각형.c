#include <stdio.h>

int main(void){
    int W, H;
    scanf("%d %d", &W, &H);

    double area = (double)W * H / 2;

    printf("%.1f\n", area);
}