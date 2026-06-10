#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print characters increasing to peak
        for (int k = 1; k <= i; k++) {
            printf("%c", 'A' + k - 1);
        }
        // Print characters decreasing from peak
        for (int k = i - 1; k >= 1; k--) {
            printf("%c", 'A' + k - 1);
        }
        printf("\n");
    }

    return 0;
}