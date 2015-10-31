#include <stdio.h>

int countDigit(int number) {
    int count = 1;
    while (number /= 10)
        count++;
    return count;
}

int power(int base, int exp) {
    int power = 1;
    for (int i = 0; i < exp; i++)
        power *= base;
    return power;
}

int KaraMul(int x, int y) {
    int a, b, c, d, result;
    if (x < 10 || y < 10)
        result = x*y;
    else {
        int shift = power(10,countDigit(x)/2);
        a = x/shift;
        b = x - a*shift;
        c = y/shift;
        d = y - c*shift;
        result = KaraMul(a,c)*shift*shift + KaraMul(b,d) + (KaraMul(a+b, c+d) -KaraMul(a,c) - KaraMul(b,d))*shift;
    }
    return result;
}

int main(void) {
    int x, y, mul;
    printf("please input two integer:");
    scanf("%d %d",&x, &y);
    mul = KaraMul(x,y);
    printf("x multiply y is %d, with the KaraMethord is %d\n", x*y, mul);
    return 0;
}

