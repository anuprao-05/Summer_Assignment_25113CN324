#include <stdio.h>

int main() {
    int start, end, i, temp, remainder, result, digits, power, j;

    printf("Enter start of range : ");
    scanf("%d", &start);

    printf("Enter end of range   : ");
    scanf("%d", &end);

    printf("\nArmstrong numbers between %d and %d are :\n", start, end);

    for (i = start; i <= end; i++) {
        result = 0;
        digits = 0;
        temp   = i;

        // Count digits
        while (temp != 0) {
            digits++;
            temp = temp / 10;
        }

        // Calculate sum of digits raised to power of digits
        temp = i;
        while (temp != 0) {
            remainder = temp % 10;

            power = 1;
            for (j = 0; j < digits; j++)
                power = power * remainder;

            result = result + power;
            temp   = temp / 10;
        }

        if (result == i)
            printf("%d\n", i);
    }

    return 0;
}