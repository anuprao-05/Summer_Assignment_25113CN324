#include <stdio.h>

// Function to print Fibonacci series up to n terms
void fibonacci(int n) {
    int a = 0, b = 1, next;

    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of terms : ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    fibonacci(n);

    return 0;
}