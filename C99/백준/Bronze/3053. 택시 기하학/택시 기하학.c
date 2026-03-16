#include <stdio.h>

int main(void){
    int R;
    scanf("%d", &R);

    double pi = 3.1415926535897932384626433832795;
    double uclidian = R*R*pi;
    double taxi = 2*R*R;

    printf("%.6f\n", uclidian);
    printf("%.6f\n", taxi);

    return 0;
}