#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

int main() {
    struct Contact contacts[MAX];
    int n = 0;
    int choice, i, j, found;
    char searchName[50];

    do {
        printf("\n========================================\n");
        printf("   CONTACT MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n >= MAX) {
                printf("\nContact list is full!\n");
            } else {
                printf("\nEnter Name  : ");
                scanf(" %[^\n]", contacts[n].name);
                printf("Enter Phone : ");
                scanf(" %[^\n]", contacts[n].phone);
                printf("Enter Email : ");
                scanf(" %[^\n]", contacts[n].email);
                n++;
                printf("\nContact added successfully!\n");
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("\nNo contacts found.\n");
            } else {
                printf("\n%-20s %-15s %-25s\n", "Name", "Phone", "Email");
                printf("------------------------------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%-20s %-15s %-25s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
                }
            }
        }

        else if (choice == 3) {
            printf("\nEnter Name to search : ");
            scanf(" %[^\n]", searchName);
            found = 0;
            for (i = 0; i < n; i++) {
                if (strstr(contacts[i].name, searchName) != NULL) {
                    printf("\nContact Found:\n");
                    printf("Name  : %s\n", contacts[i].name);
                    printf("Phone : %s\n", contacts[i].phone);
                    printf("Email : %s\n", contacts[i].email);
                    found = 1;
                }
            }
            if (found == 0)
                printf("\nNo contact found with name '%s'.\n", searchName);
        }

        else if (choice == 4) {
            printf("\nEnter Name to update : ");
            scanf(" %[^\n]", searchName);
            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(contacts[i].name, searchName) == 0) {
                    printf("Enter new Phone : ");
                    scanf(" %[^\n]", contacts[i].phone);
                    printf("Enter new Email : ");
                    scanf(" %[^\n]", contacts[i].email);
                    printf("\nContact updated successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nContact '%s' not found.\n", searchName);
        }

        else if (choice == 5) {
            printf("\nEnter Name to delete : ");
            scanf(" %[^\n]", searchName);
            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(contacts[i].name, searchName) == 0) {
                    for (j = i; j < n - 1; j++) {
                        contacts[j] = contacts[j + 1];
                    }
                    n--;
                    printf("\nContact deleted successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nContact '%s' not found.\n", searchName);
        }

        else if (choice == 6) {
            printf("\nExiting program. Goodbye!\n");
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}