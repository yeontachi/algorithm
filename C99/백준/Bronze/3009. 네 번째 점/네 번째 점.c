#include <stdio.h>

int main(void){
    int xp[3];
    int yp[3];

    for(int i=0; i<3; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        xp[i] = x;
        yp[i] = y;
    }

    int x = xp[0];
    int y = yp[0];
    int xc = 0;
    int yc = 0;

    int answer_x = 0;
    int answer_y = 0;

    for(int i=0; i<3; ++i){
        if(x==xp[i]) xc++;
        if(y==yp[i]) yc++;
    }

    if(xc==1) answer_x = x;
    else{
        for(int i=0; i<3; ++i){
            if(x!=xp[i]) answer_x = xp[i];
        }
    }
    if(yc==1) answer_y = y;
    else{
        for(int i=0; i<3; ++i){
            if(y!=yp[i]) answer_y = yp[i];
        }
    }
    printf("%d %d", answer_x, answer_y);
}