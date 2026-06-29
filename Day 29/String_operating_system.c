#include <stdio.h>
#include <string.h>

int main() {
    char str[100], str2[100];
    int choice, i, j, k, length;
    char ch, temp;

    printf("Enter a string : ");
    scanf("%s", str);

    do {
        printf("\n========================================\n");
        printf("   STRING OPERATIONS SYSTEM\n");
        printf("========================================\n");
        printf(" 1. Display String\n");
        printf(" 2. Find String Length\n");
        printf(" 3. Reverse String\n");
        printf(" 4. Count Vowels and Consonants\n");
        printf(" 5. Convert to Uppercase\n");
        printf(" 6. Convert to Lowercase\n");
        printf(" 7. Check Palindrome\n");
        printf(" 8. Check String Rotation\n");
        printf(" 9. Compress String\n");
        printf("10. Remove Duplicate Characters\n");
        printf("11. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nCurrent string = %s\n", str);
        }

        else if (choice == 2) {
            length = 0;
            while (str[length] != '\0')
                length++;
            printf("\nLength of string = %d\n", length);
        }

        else if (choice == 3) {
            length = 0;
            while (str[length] != '\0')
                length++;

            int left = 0, right = length - 1;
            while (left < right) {
                temp        = str[left];
                str[left]   = str[right];
                str[right]  = temp;
                left++;
                right--;
            }
            printf("\nReversed string = %s\n", str);
        }

        else if (choice == 4) {
            int vowels = 0, consonants = 0;
            for (i = 0; str[i] != '\0'; i++) {
                ch = str[i];
                if (ch >= 'A' && ch <= 'Z')
                    ch = ch + 32;

                if (ch >= 'a' && ch <= 'z') {
                    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                        vowels++;
                    else
                        consonants++;
                }
            }
            printf("\nVowels     = %d\n", vowels);
            printf("Consonants = %d\n", consonants);
        }

        else if (choice == 5) {
            for (i = 0; str[i] != '\0'; i++) {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] = str[i] - 32;
            }
            printf("\nUppercase string = %s\n", str);
        }

        else if (choice == 6) {
            for (i = 0; str[i] != '\0'; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] = str[i] + 32;
            }
            printf("\nLowercase string = %s\n", str);
        }

        else if (choice == 7) {
            length = 0;
            while (str[length] != '\0')
                length++;

            int isPalindrome = 1;
            for (i = 0; i < length / 2; i++) {
                if (str[i] != str[length - 1 - i]) {
                    isPalindrome = 0;
                    break;
                }
            }

            if (isPalindrome == 1)
                printf("\n%s is a Palindrome.\n", str);
            else
                printf("\n%s is NOT a Palindrome.\n", str);
        }

        else if (choice == 8) {
            printf("\nEnter second string to compare : ");
            scanf("%s", str2);

            if (strlen(str) != strlen(str2)) {
                printf("Not a rotation (different lengths).\n");
            } else {
                char doubled[200];
                strcpy(doubled, str);
                strcat(doubled, str);

                if (strstr(doubled, str2) != NULL)
                    printf("%s is a rotation of %s\n", str2, str);
                else
                    printf("%s is NOT a rotation of %s\n", str2, str);
            }
        }

        else if (choice == 9) {
            char compressed[100];
            int count;
            i = 0;
            j = 0;

            while (str[i] != '\0') {
                count = 1;
                while (str[i] == str[i + 1] && str[i + 1] != '\0') {
                    count++;
                    i++;
                }
                compressed[j] = str[i];
                j++;

                if (count > 1) {
                    char numStr[10];
                    int n2 = 0, temp2 = count;
                    while (temp2 != 0) {
                        numStr[n2] = (temp2 % 10) + '0';
                        n2++;
                        temp2 = temp2 / 10;
                    }
                    while (n2 > 0) {
                        n2--;
                        compressed[j] = numStr[n2];
                        j++;
                    }
                }
                i++;
            }
            compressed[j] = '\0';
            strcpy(str, compressed);
            printf("\nCompressed string = %s\n", str);
        }

        else if (choice == 10) {
            char result[100];
            k = 0;
            for (i = 0; str[i] != '\0'; i++) {
                int isDuplicate = 0;
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
            strcpy(str, result);
            printf("\nString after removing duplicates = %s\n", str);
        }

        else if (choice == 11) {
            printf("\nExiting program. Goodbye!\n");
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 11);

    return 0;
}