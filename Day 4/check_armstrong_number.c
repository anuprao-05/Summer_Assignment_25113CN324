#include <stdio.h>

int main() {
    int num, original, remainder, result = 0, digits = 0;
    int temp;

    printf("Enter a number : ");
    scanf("%d", &num);

    original = num;
    temp     = num;

    while (temp != 0) {
        digits++;
        temp = temp / 10;
    }

    temp = num;
    while (temp != 0) {
        remainder = temp % 10;

        int power = 1;
        for (int i = 0; i < digits; i++)
            power = power * remainder;

        result = result + power;
        temp   = temp / 10;
    }

    if (result == original)
        printf("%d is an Armstrong number.\n", original);
    else
        printf("%d is NOT an Armstrong number.\n", original);

    return 0;
}