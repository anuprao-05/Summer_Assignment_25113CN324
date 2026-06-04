#include <stdio.h>

int main() {
    int n, i;
    int first = 0, second = 1, next;

    printf("Enter the value of N : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    if (n == 1) {
        printf("%dth Fibonacci term = 0\n", n);
        return 0;
    }

    if (n == 2) {
        printf("%dth Fibonacci term = 1\n", n);
        return 0;
    }

    for (i = 3; i <= n; i++) {
        next   = first + second;
        first  = second;
        second = next;
    }

    printf("%dth Fibonacci term = %d\n", n, second);

    return 0;
}