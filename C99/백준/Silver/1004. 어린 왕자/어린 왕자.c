#include <stdio.h>
#include <stdbool.h>

bool is_in_Circle(int x, int y, int r, int a, int b){
    return (x - a) * (x - a) + (y - b)*(y - b) < r*r;
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int n;
        scanf("%d", &n);

        int count = 0;

        while(n--){
            int a, b, r;
            scanf("%d %d %d", &a, &b, &r);

            if(is_in_Circle(x1, y1, r, a, b) && is_in_Circle(x2, y2, r, a, b)){
                continue;
            }

            if(is_in_Circle(x1, y1, r, a, b) || is_in_Circle(x2, y2, r, a, b)){
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}