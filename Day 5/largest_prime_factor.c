#include <stdio.h>

int main() {
    int num, i, largest = -1;

    printf("Enter a number : ");
    scanf("%d", &num);

    // Divide out all factors of 2
    while (num % 2 == 0) {
        largest = 2;
        num     = num / 2;
    }

    // Check for odd prime factors
    for (i = 3; i <= num; i = i + 2) {
        while (num % i == 0) {
            largest = i;
            num     = num / i;
        }
    }

    if (largest == -1)
        printf("No prime factor found.\n");
    else
        printf("Largest Prime Factor = %d\n", largest);

    return 0;
}