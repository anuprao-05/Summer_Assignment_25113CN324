#include <stdio.h>

int main() {
    int n, i;
    int even = 0, odd = 0;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements :\n", n);
    for (i = 0; i < n; i++) {
        printf("Element[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("\nArray elements are : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nEven elements count = %d\n", even);
    printf("Odd  elements count = %d\n",  odd);

    return 0;
}