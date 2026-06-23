#include <stdio.h>

int main() {
    char str[100];
    int i, j, maxCount = 0, count;
    char maxChar;

    printf("Enter a string: ");
    gets(str);

    for(i = 0; str[i] != '\0'; i++) {
        count = 1;

        for(j = i + 1; str[j] != '\0'; j++) {
            if(str[i] == str[j])
                count++;
        }

        if(count > maxCount) {
            maxCount = count;
            maxChar = str[i];
        }
    }

    printf("Maximum Occurring Character: %c", maxChar);
    printf("\nFrequency: %d", maxCount);

    return 0;
}