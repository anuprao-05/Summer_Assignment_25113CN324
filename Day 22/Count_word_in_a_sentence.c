#include <stdio.h>

int main() {
    char str[200];
    int i, words = 1;

    printf("Enter a sentence: ");
    gets(str);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ' && str[i+1] != ' ')
            words++;
    }

    printf("Total Words = %d", words);

    return 0;
}