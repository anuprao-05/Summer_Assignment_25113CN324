#include <stdio.h>

int main() {
    int a, b, lcm;

    printf("Enter first number  : ");
    scanf("%d", &a);

    printf("Enter second number : ");
    scanf("%d", &b);

    // LCM starts from the larger number
    lcm = (a > b) ? a : b;

    while (1) {
        if (lcm % a == 0 && lcm % b == 0) {
            printf("LCM of %d and %d = %d\n", a, b, lcm);
            break;
        }
        lcm++;
    }

    return 0;
}