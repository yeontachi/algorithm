#include <stdio.h>
/*
$$S = (x_2 - x_1)(y_3 - y_1) - (y_2 - y_1)(x_3 - x_1)$$
S > 0 : 반시계 방향
S < 0 : 시계 방향
S = 0 : 일직선
*/
typedef struct{
    int x;
    int y;
} Point;

int check_rotate_dir(Point p1, Point p2, Point p3){
    // 벡터의 외적 공식 적용
    int cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

    if (cross_product > 0) return 1;       // 반시계
    else if (cross_product < 0) return -1; // 시계
    else return 0;                         // 일직선
}

int main(void){
    Point p[3];

    for(int i=0; i<3; ++i){
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    int result = check_rotate_dir(p[0], p[1], p[2]);

    printf("%d\n", result);

    return 0;
}