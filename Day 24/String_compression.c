#include <stdio.h>

int main() {
    char str[100], compressed[100];
    int i = 0, j = 0, count;

    printf("Enter a string : ");
    scanf("%s", str);

    while (str[i] != '\0') {
        count = 1;

        while (str[i] == str[i + 1] && str[i + 1] != '\0') {
            count++;
            i++;
        }

        compressed[j] = str[i];
        j++;

        if (count > 1) {
            // Convert count to characters and store
            char numStr[10];
            int k = 0, temp = count;

            while (temp != 0) {
                numStr[k] = (temp % 10) + '0';
                k++;
                temp = temp / 10;
            }

            // Reverse digits and add to compressed string
            while (k > 0) {
                k--;
                compressed[j] = numStr[k];
                j++;
            }
        }

        i++;
    }

    compressed[j] = '\0';

    printf("Original string   = %s\n", str);
    printf("Compressed string = %s\n", compressed);

    return 0;
}