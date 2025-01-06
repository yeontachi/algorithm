#include <stdio.h>

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(void){
    int Numerator1;
    int Numerator2;
    int Denominator1;
    int Denominator2;

    scanf("%d %d", &Numerator1, &Denominator1);
    scanf("%d %d", &Numerator2, &Denominator2);

    int num1 = Numerator1*Denominator2+Numerator2*Denominator1;
    int num2 = Denominator1*Denominator2;

    int x=gcd(num1, num2);

    printf("%d %d", num1/x, num2/x);

    return 0;
}