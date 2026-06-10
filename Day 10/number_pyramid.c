#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print numbers increasing to peak
        for (int k = 1; k <= i; k++) {
            printf("%d", k);
        }
        // Print numbers decreasing from peak
        for (int k = i - 1; k >= 1; k--) {
            printf("%d", k);
        }
        printf("\n");
    }

    return 0;
}