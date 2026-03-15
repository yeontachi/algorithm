#include <stdio.h>

int main(void){
    int x, y, w, h;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    int m[4];

    m[0] = h - y;
    m[1] = w - x;
    m[2] = x;
    m[3] = y;

    int min = 1001;
    for(int i=0; i<4; ++i){
        if(m[i] <=min) min = m[i];
    }

    printf("%d\n", min);

    return 0;
}