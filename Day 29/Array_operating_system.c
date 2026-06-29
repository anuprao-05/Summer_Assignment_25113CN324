#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n, i, j, choice, temp, key;
    int largest, second, smallest, even, odd, count, k;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter %d elements :\n", n);
    for (i = 0; i < n; i++) {
        printf("Element[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n========================================\n");
        printf("   ARRAY OPERATIONS SYSTEM\n");
        printf("========================================\n");
        printf(" 1. Display Array\n");
        printf(" 2. Sum and Average\n");
        printf(" 3. Largest and Smallest Element\n");
        printf(" 4. Second Largest Element\n");
        printf(" 5. Count Even and Odd Elements\n");
        printf(" 6. Linear Search\n");
        printf(" 7. Frequency of an Element\n");
        printf(" 8. Reverse Array\n");
        printf(" 9. Rotate Array Left\n");
        printf("10. Rotate Array Right\n");
        printf("11. Move Zeroes to End\n");
        printf("12. Remove Duplicates\n");
        printf("13. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nArray elements : ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        else if (choice == 2) {
            float sum = 0, average;
            for (i = 0; i < n; i++)
                sum = sum + arr[i];
            average = sum / n;
            printf("\nSum     = %.0f\n", sum);
            printf("Average = %.2f\n", average);
        }

        else if (choice == 3) {
            largest = arr[0];
            smallest = arr[0];
            for (i = 1; i < n; i++) {
                if (arr[i] > largest)
                    largest = arr[i];
                if (arr[i] < smallest)
                    smallest = arr[i];
            }
            printf("\nLargest  element = %d\n", largest);
            printf("Smallest element = %d\n", smallest);
        }

        else if (choice == 4) {
            largest = arr[0];
            second  = arr[0];
            for (i = 1; i < n; i++) {
                if (arr[i] > largest)
                    largest = arr[i];
            }
            for (i = 0; i < n; i++) {
                if (arr[i] > second && arr[i] < largest)
                    second = arr[i];
            }
            printf("\nLargest element        = %d\n", largest);
            printf("Second Largest element = %d\n", second);
        }

        else if (choice == 5) {
            even = 0;
            odd  = 0;
            for (i = 0; i < n; i++) {
                if (arr[i] % 2 == 0)
                    even++;
                else
                    odd++;
            }
            printf("\nEven elements count = %d\n", even);
            printf("Odd  elements count = %d\n", odd);
        }

        else if (choice == 6) {
            int found = 0;
            printf("\nEnter element to search : ");
            scanf("%d", &key);
            for (i = 0; i < n; i++) {
                if (arr[i] == key) {
                    printf("Element %d found at position %d\n", key, i + 1);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("Element %d not found in array.\n", key);
        }

        else if (choice == 7) {
            count = 0;
            printf("\nEnter element to find frequency : ");
            scanf("%d", &key);
            for (i = 0; i < n; i++) {
                if (arr[i] == key)
                    count++;
            }
            printf("Frequency of %d = %d\n", key, count);
        }

        else if (choice == 8) {
            int left = 0, right = n - 1;
            while (left < right) {
                temp        = arr[left];
                arr[left]   = arr[right];
                arr[right]  = temp;
                left++;
                right--;
            }
            printf("\nArray reversed successfully!\n");
            printf("Array elements : ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        else if (choice == 9) {
            printf("\nEnter number of rotations : ");
            scanf("%d", &k);
            for (int r = 0; r < k; r++) {
                temp = arr[0];
                for (i = 0; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                arr[n - 1] = temp;
            }
            printf("Array rotated left successfully!\n");
            printf("Array elements : ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        else if (choice == 10) {
            printf("\nEnter number of rotations : ");
            scanf("%d", &k);
            for (int r = 0; r < k; r++) {
                temp = arr[n - 1];
                for (i = n - 1; i > 0; i--)
                    arr[i] = arr[i - 1];
                arr[0] = temp;
            }
            printf("Array rotated right successfully!\n");
            printf("Array elements : ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        else if (choice == 11) {
            j = 0;
            for (i = 0; i < n; i++) {
                if (arr[i] != 0) {
                    arr[j] = arr[i];
                    j++;
                }
            }
            while (j < n) {
                arr[j] = 0;
                j++;
            }
            printf("\nZeroes moved to end successfully!\n");
            printf("Array elements : ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        else if (choice == 12) {
            for (i = 0; i < n; i++) {
                for (j = i + 1; j < n; j++) {
                    if (arr[i] == arr[j]) {
                        for (int m = j; m < n - 1; m++)
                            arr[m] = arr[m + 1];
                        n--;
                        j--;
                    }
                }
            }
            printf("\nDuplicates removed successfully!\n");
            printf("Array elements : ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        else if (choice == 13) {
            printf("\nExiting program. Goodbye!\n");
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 13);

    return 0;
}