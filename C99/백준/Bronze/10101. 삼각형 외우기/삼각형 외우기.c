#include <stdio.h>

int main(void){
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    int sum = a + b + c;

    if(sum != 180){
        printf("Error\n");
        return 0;
    }

    if(a==b || b==c || a==c){
        if(a==60){
            printf("Equilateral\n");
            return 0;
        }
        printf("Isosceles\n");
        return 0;
    }
    else printf("Scalene\n");

    return 0;
}