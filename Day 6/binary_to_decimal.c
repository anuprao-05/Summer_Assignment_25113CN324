#include <stdio.h>

int main() {
    long long binary;
    int decimal = 0, remainder, base = 1;

    printf("Enter a binary number : ");
    scanf("%lld", &binary);

    long long temp = binary;

    while (temp != 0) {
        remainder = temp % 10;
        decimal   = decimal + remainder * base;
        base      = base * 2;
        temp      = temp / 10;
    }

    printf("Decimal = %d\n", decimal);

    return 0;
}