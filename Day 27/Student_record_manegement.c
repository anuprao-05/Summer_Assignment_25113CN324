#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student students[MAX];
    int n = 0;
    int choice, i, j, roll, found;

    do {
        printf("\n========================================\n");
        printf("   STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n >= MAX) {
                printf("\nRecord list is full!\n");
            } else {
                printf("\nEnter Roll Number : ");
                scanf("%d", &students[n].roll);
                printf("Enter Name        : ");
                scanf("%s", students[n].name);
                printf("Enter Marks       : ");
                scanf("%f", &students[n].marks);
                n++;
                printf("\nStudent added successfully!\n");
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("\nNo records found.\n");
            } else {
                printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
                printf("----------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%-10d %-20s %-10.2f\n", students[i].roll, students[i].name, students[i].marks);
                }
            }
        }

        else if (choice == 3) {
            printf("\nEnter Roll Number to search : ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++) {
                if (students[i].roll == roll) {
                    printf("\nRecord Found:\n");
                    printf("Roll No : %d\n", students[i].roll);
                    printf("Name    : %s\n", students[i].name);
                    printf("Marks   : %.2f\n", students[i].marks);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nStudent with Roll Number %d not found.\n", roll);
        }

        else if (choice == 4) {
            printf("\nEnter Roll Number to update : ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++) {
                if (students[i].roll == roll) {
                    printf("Enter new Name  : ");
                    scanf("%s", students[i].name);
                    printf("Enter new Marks : ");
                    scanf("%f", &students[i].marks);
                    printf("\nRecord updated successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nStudent with Roll Number %d not found.\n", roll);
        }

        else if (choice == 5) {
            printf("\nEnter Roll Number to delete : ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++) {
                if (students[i].roll == roll) {
                    for (j = i; j < n - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    n--;
                    printf("\nRecord deleted successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nStudent with Roll Number %d not found.\n", roll);
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