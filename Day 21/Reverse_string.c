#include <stdio.h>

int main() {
    char str[100];
    int length = 0, i;
    char temp;

    printf("Enter a string : ");
    scanf("%s", str);

    // Find length of string
    while (str[length] != '\0') {
        length++;
    }

    // Reverse the string
    int left = 0, right = length - 1;
    while (left < right) {
        temp        = str[left];
        str[left]   = str[right];
        str[right]  = temp;
        left++;
        right--;
    }

    printf("Reversed string = %s\n", str);

    return 0;
}