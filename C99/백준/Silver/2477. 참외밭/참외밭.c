#include <stdio.h>

typedef struct{
    int dir;
    int len;
} dirLen;

int mini_square_area(int dir1, int len1, int dir2, int len2){
    if(dir1 == 4 && dir2 == 1){ return len1 * len2; }
    else if(dir1 == 2 && dir2 == 4){ return len1 * len2; }
    else if(dir1 == 1 && dir2 == 3){ return len1 * len2; } 
    else if(dir1 == 3 && dir2 == 2){ return len1 * len2; }
    
    return 0; 
}

int main(void){
    int K;
    scanf("%d", &K);

    dirLen dirLenArr[6];

    int maxx = 0;
    int maxy = 0;

    for(int i=0; i<6; ++i){
        scanf("%d %d", &dirLenArr[i].dir, &dirLenArr[i].len);

        if(dirLenArr[i].dir == 4 || dirLenArr[i].dir == 3){
            if(maxx < dirLenArr[i].len){
                maxx = dirLenArr[i].len;
            }
        }
        else{
            if(maxy < dirLenArr[i].len){
                maxy = dirLenArr[i].len;
            }
        }
    }

    int squareArea = maxx * maxy;
    int miniSquareArea = 0;

    for(int i=0; i<6; ++i){
        int prev = (i == 0) ? 5 : i - 1;
        int area = mini_square_area(dirLenArr[prev].dir, dirLenArr[prev].len, dirLenArr[i].dir, dirLenArr[i].len);
        
        if(area > 0){
            miniSquareArea = area;
            break; 
        }
    }

    int result = squareArea - miniSquareArea;
    printf("%d", result * K);
    
    return 0;
}