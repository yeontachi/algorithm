#include <stdio.h>

// 2차원 좌표를 담을 구조체
typedef struct {
    long long x;
    long long y;
} Point;

// 세 점의 방향성을 판별하는 CCW 함수
// 반환값: 반시계 방향(1), 시계 방향(-1), 일직선(0)
long long ccw(Point a, Point b, Point c) {
    long long val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (val > 0) return 1;
    else if (val < 0) return -1;
    else return 0;
}

// 두 점의 위치를 바꾸는 함수 (일직선 예외 처리용)
void swap(Point* p1, Point* p2) {
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// 점의 크기 비교 (x좌표 먼저 비교, 같으면 y좌표 비교)
// p1이 p2보다 작거나 같으면 1 반환
int is_less_or_equal(Point p1, Point p2) {
    if (p1.x == p2.x) return p1.y <= p2.y;
    return p1.x <= p2.x;
}

int main() {
    Point p1, p2, p3, p4;
    
    // 입력 받기
    scanf("%lld %lld %lld %lld", &p1.x, &p1.y, &p2.x, &p2.y);
    scanf("%lld %lld %lld %lld", &p3.x, &p3.y, &p4.x, &p4.y);

    // 각 선분을 기준으로 CCW 계산
    long long abc = ccw(p1, p2, p3);
    long long abd = ccw(p1, p2, p4);
    long long cda = ccw(p3, p4, p1);
    long long cdb = ccw(p3, p4, p2);

    // 1. 네 점이 모두 일직선 상에 있는 경우 (선분이 겹치는지 판단)
    if (abc * abd == 0 && cda * cdb == 0) {
        // 크기순으로 정렬 (p1 <= p2, p3 <= p4)
        if (!is_less_or_equal(p1, p2)) swap(&p1, &p2);
        if (!is_less_or_equal(p3, p4)) swap(&p3, &p4);

        // 두 선분이 포개어지는지 확인
        if (is_less_or_equal(p1, p4) && is_less_or_equal(p3, p2)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    } 
    // 2. 일반적인 교차 (끝점이 만나는 경우 포함)
    else if (abc * abd <= 0 && cda * cdb <= 0) {
        printf("1\n");
    } 
    // 3. 교차하지 않음
    else {
        printf("0\n");
    }

    return 0;
}