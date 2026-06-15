#include <stdio.h>

int main() {
    int n, i, temp;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements :\n", n);
    for (i = 0; i < n; i++) {
        printf("Element[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array  : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Reverse the array
    int left = 0, right = n - 1;
    while (left < right) {
        temp        = arr[left];
        arr[left]   = arr[right];
        arr[right]  = temp;
        left++;
        right--;
    }

    printf("\nReversed array  : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}