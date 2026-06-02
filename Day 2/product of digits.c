#include <stdio.h>

int main() {
    int num, digit, product = 1;

    printf("Enter a number : ");
    scanf("%d", &num);

    if (num < 0)
        num = -num;

    while (num != 0) {
        digit   = num % 10;
        product = product * digit;
        num     = num / 10;
    }

    printf("Product of Digits = %d\n", product);

    return 0;
}