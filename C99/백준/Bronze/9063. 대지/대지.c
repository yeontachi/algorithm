#include <stdio.h>

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int main(void){
    int N;
    scanf("%d", &N);

    int maxx=-10001, maxy=-10, minx=10001, miny=10001;

    while(N--){
        int a, b;
        scanf("%d %d", &a, &b);
        maxx = max(maxx, a);
        maxy = max(maxy, b);
        minx = min(minx, a);
        miny = min(miny, b);
    }
    
    int result = (maxx - minx) * (maxy - miny);

    printf("%d", result);

    return 0;
}