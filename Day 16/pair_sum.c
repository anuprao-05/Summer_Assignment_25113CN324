#include <stdio.h>

int main() {
    int arr[100], n, sum, i, j, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the sum to find: ");
    scanf("%d", &sum);

    // Find pair
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == sum) {
                printf("Pair found: %d and %d\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if(found == 0) {
        printf("No pair found.");
    }

    return 0;
}