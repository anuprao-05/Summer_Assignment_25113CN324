#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];
    char longest[50], word[50];
    int i = 0, j = 0;

    printf("Enter a sentence : ");
    fgets(sentence, sizeof(sentence), stdin);

    longest[0] = '\0';
    j = 0;

    for (i = 0; i <= strlen(sentence); i++) {
        if (sentence[i] != ' ' && sentence[i] != '\0' && sentence[i] != '\n') {
            word[j] = sentence[i];
            j++;
        } else {
            word[j] = '\0';

            if (strlen(word) > strlen(longest))
                strcpy(longest, word);

            j = 0;
        }
    }

    printf("Longest word = %s\n", longest);
    printf("Length       = %d\n", (int)strlen(longest));

    return 0;
}