#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued;   // 0 = Available, 1 = Issued
};

int main() {
    struct Book books[MAX];
    int n = 0;
    int choice, i, j, id, found;

    do {
        printf("\n========================================\n");
        printf("   LIBRARY MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n >= MAX) {
                printf("\nLibrary is full!\n");
            } else {
                printf("\nEnter Book ID     : ");
                scanf("%d", &books[n].id);
                printf("Enter Title       : ");
                scanf(" %[^\n]", books[n].title);
                printf("Enter Author      : ");
                scanf(" %[^\n]", books[n].author);
                books[n].isIssued = 0;
                n++;
                printf("\nBook added successfully!\n");
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("\nNo books found.\n");
            } else {
                printf("\n%-6s %-20s %-20s %-10s\n", "ID", "Title", "Author", "Status");
                printf("--------------------------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%-6d %-20s %-20s %-10s\n",
                           books[i].id,
                           books[i].title,
                           books[i].author,
                           books[i].isIssued == 1 ? "Issued" : "Available");
                }
            }
        }

        else if (choice == 3) {
            printf("\nEnter Book ID to search : ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++) {
                if (books[i].id == id) {
                    printf("\nBook Found:\n");
                    printf("ID     : %d\n", books[i].id);
                    printf("Title  : %s\n", books[i].title);
                    printf("Author : %s\n", books[i].author);
                    printf("Status : %s\n", books[i].isIssued == 1 ? "Issued" : "Available");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nBook with ID %d not found.\n", id);
        }

        else if (choice == 4) {
            printf("\nEnter Book ID to issue : ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++) {
                if (books[i].id == id) {
                    found = 1;
                    if (books[i].isIssued == 1)
                        printf("\nBook is already issued!\n");
                    else {
                        books[i].isIssued = 1;
                        printf("\nBook issued successfully!\n");
                    }
                    break;
                }
            }
            if (found == 0)
                printf("\nBook with ID %d not found.\n", id);
        }

        else if (choice == 5) {
            printf("\nEnter Book ID to return : ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++) {
                if (books[i].id == id) {
                    found = 1;
                    if (books[i].isIssued == 0)
                        printf("\nBook was not issued!\n");
                    else {
                        books[i].isIssued = 0;
                        printf("\nBook returned successfully!\n");
                    }
                    break;
                }
            }
            if (found == 0)
                printf("\nBook with ID %d not found.\n", id);
        }

        else if (choice == 6) {
            printf("\nEnter Book ID to delete : ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++) {
                if (books[i].id == id) {
                    for (j = i; j < n - 1; j++) {
                        books[j] = books[j + 1];
                    }
                    n--;
                    printf("\nBook deleted successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nBook with ID %d not found.\n", id);
        }

        else if (choice == 7) {
            printf("\nExiting program. Goodbye!\n");
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}