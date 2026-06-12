#include <stdio.h>

int isPalindrome(int n) {
    int original = n, reversed = 0;

    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return original == reversed;
}

int main() {
    int num;

    printf("Enter a number : ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d is a Palindrome number\n", num);
    } else {
        printf("%d is not a Palindrome number\n", num);
    }

    return 0;
}