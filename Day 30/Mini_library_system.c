#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    char bookNames[MAX][50];
    int isIssued[MAX];
    int n = 0;
    int choice, i, found;
    char searchName[50];

    do {
        printf("\n========================================\n");
        printf("   MINI LIBRARY SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n >= MAX) {
                printf("\nLibrary is full!\n");
            } else {
                printf("\nEnter Book Name : ");
                scanf(" %[^\n]", bookNames[n]);
                isIssued[n] = 0;
                n++;
                printf("\nBook added successfully!\n");
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("\nNo books found.\n");
            } else {
                printf("\n%-30s %-10s\n", "Book Name", "Status");
                printf("------------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%-30s %-10s\n", bookNames[i], isIssued[i] == 1 ? "Issued" : "Available");
                }
            }
        }

        else if (choice == 3) {
            printf("\nEnter Book Name to issue : ");
            scanf(" %[^\n]", searchName);
            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(bookNames[i], searchName) == 0) {
                    found = 1;
                    if (isIssued[i] == 1)
                        printf("\nBook is already issued!\n");
                    else {
                        isIssued[i] = 1;
                        printf("\nBook issued successfully!\n");
                    }
                    break;
                }
            }
            if (found == 0)
                printf("\nBook '%s' not found.\n", searchName);
        }

        else if (choice == 4) {
            printf("\nEnter Book Name to return : ");
            scanf(" %[^\n]", searchName);
            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(bookNames[i], searchName) == 0) {
                    found = 1;
                    if (isIssued[i] == 0)
                        printf("\nBook was not issued!\n");
                    else {
                        isIssued[i] = 0;
                        printf("\nBook returned successfully!\n");
                    }
                    break;
                }
            }
            if (found == 0)
                printf("\nBook '%s' not found.\n", searchName);
        }

        else if (choice == 5) {
            printf("\nExiting program. Goodbye!\n");
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}