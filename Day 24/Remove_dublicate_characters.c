#include <stdio.h>

int main() {
    char str[100], result[100];
    int i, j, k, isDuplicate;

    printf("Enter a string : ");
    scanf("%s", str);

    k = 0;

    for (i = 0; str[i] != '\0'; i++) {
        isDuplicate = 0;

        // Check if str[i] already exists in result
        for (j = 0; j < k; j++) {
            if (result[j] == str[i]) {
                isDuplicate = 1;
                break;
            }
        }

        if (isDuplicate == 0) {
            result[k] = str[i];
            k++;
        }
    }

    result[k] = '\0';

    printf("Original string  = %s\n", str);
    printf("After removing duplicates = %s\n", result);

    return 0;
}