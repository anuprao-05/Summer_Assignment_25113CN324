#include <stdio.h>

int main() {
    int n1, n2, i, j, found;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter elements of first array:\n");
    for(i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter elements of second array:\n");
    for(i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    printf("Union Array: ");

    for(i = 0; i < n1; i++)
        printf("%d ", arr1[i]);

    for(i = 0; i < n2; i++) {
        found = 0;

        for(j = 0; j < n1; j++) {
            if(arr2[i] == arr1[j]) {
                found = 1;
                break;
            }
        }

        if(!found)
            printf("%d ", arr2[i]);
    }

    return 0;
}