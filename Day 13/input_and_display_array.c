#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements :\n", n);
    for (i = 0; i < n; i++) {
        printf("Element[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements are :\n");
    for (i = 0; i < n; i++)
        printf("Element[%d] = %d\n", i, arr[i]);

    return 0;
}