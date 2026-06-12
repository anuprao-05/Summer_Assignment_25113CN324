#include <stdio.h>

// Function to check if a number is a perfect number
int isPerfect(int n) {
    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum == n;
}

int main() {
    int num;

    printf("Enter a number : ");
    scanf("%d", &num);

    if (isPerfect(num)) {
        printf("%d is a Perfect number\n", num);
    } else {
        printf("%d is not a Perfect number\n", num);
    }

    return 0;
}