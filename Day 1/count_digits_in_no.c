#include <stdio.h>

int main() {
    int num, count = 0;

    printf("Enter a number : ");
    scanf("%d", &num);

    if (num < 0)
        num = -num;

    if (num == 0) {
        printf("Total Digits = 1\n");
        return 0;
    }

    while (num != 0) {
        num = num / 10;
        count++;
    }

    printf("Total Digits = %d\n", count);

    return 0;
}