#include <stdio.h>

int main() {
    char str[100];
    int i, vowels = 0, consonants = 0;
    char ch;

    printf("Enter a string : ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        ch = str[i];

        // Convert uppercase to lowercase
        if (ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    printf("\nString          : %s\n", str);
    printf("Vowels          = %d\n", vowels);
    printf("Consonants      = %d\n", consonants);

    return 0;
}