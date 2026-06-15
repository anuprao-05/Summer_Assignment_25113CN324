#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements :\n", n);
    for (i = 0; i < n; i++) {
        printf("Element[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Move zeroes to end
    j = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[j] = arr[i];
            j++;
        }
    }

    // Fill remaining positions with zero
    while (j < n) {
        arr[j] = 0;
        j++;
    }

    printf("\nAfter moving  : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}