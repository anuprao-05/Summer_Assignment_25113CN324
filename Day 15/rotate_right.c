#include <stdio.h>

int main() {
    int n, i, k, temp;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements :\n", n);
    for (i = 0; i < n; i++) {
        printf("Element[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter number of rotations : ");
    scanf("%d", &k);

    printf("\nOriginal array : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Rotate right k times
    for (int r = 0; r < k; r++) {
        temp = arr[n - 1];
        for (i = n - 1; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = temp;
    }

    printf("\nRotated array  : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}