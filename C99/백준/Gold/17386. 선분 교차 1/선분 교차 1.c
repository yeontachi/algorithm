#include <stdio.h>

typedef struct {
    long long x;
    long long y;
} Point;

// 세 점 A, B, C의 방향성을 판별하는 CCW 함수
int ccw(Point a, Point b, Point c) {
    // 외적 공식을 이용한 방향 판별
    // (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x)
    long long op = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    
    if (op > 0) return 1;       // 반시계 방향
    else if (op < 0) return -1; // 시계 방향
    else return 0;              // 일직선
}

int main(void) {
    Point p1, p2, p3, p4;

    // L1의 양 끝 점 입력
    scanf("%lld %lld %lld %lld", &p1.x, &p1.y, &p2.x, &p2.y);
    // L2의 양 끝 점 입력
    scanf("%lld %lld %lld %lld", &p3.x, &p3.y, &p4.x, &p4.y);

    // L1(p1, p2)을 기준으로 p3, p4가 서로 반대편에 있는지 확인
    int check_L1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    
    // L2(p3, p4)를 기준으로 p1, p2가 서로 반대편에 있는지 확인
    int check_L2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    // 문제 조건: "세 점이 일직선 위에 있는 경우는 없다"
    // 따라서 ccw 값이 0이 되는 경우는 고려하지 않아도 됨
    if (check_L1 < 0 && check_L2 < 0) {
        printf("1\n"); // 교차함
    } else {
        printf("0\n"); // 교차하지 않음
    }

    return 0;
}