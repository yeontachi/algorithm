#include <stdio.h>
#include <math.h>

int main(void){
    int d1, d2;
    scanf("%d", &d1);
    scanf("%d", &d2);

    double pi = 3.141592;

    double circumference = 2*d1 + 2*d2*pi;
    printf("%.6f", circumference);
}