#include <stdio.h>
#include <string.h>

#define MAX 50

/* ---------- Global Data (Parallel Arrays) ---------- */
int rollNo[MAX];
char names[MAX][50];
float marks[MAX][3];     // 3 subjects
float total[MAX];
float percentage[MAX];
char grade[MAX];
int n = 0;               // current number of students

/* ---------- Function Prototypes ---------- */
void addStudent();
void displayAll();
void searchStudent();
void updateStudent();
void deleteStudent();
void calculateResults();
void topperReport();
void sortByPercentage();
char calculateGrade(float perc);
void showMenu();

/* ---------- Main Function ---------- */
int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent();       break;
            case 2: displayAll();       break;
            case 3: searchStudent();    break;
            case 4: updateStudent();    break;
            case 5: deleteStudent();    break;
            case 6: calculateResults(); break;
            case 7: topperReport();     break;
            case 8: sortByPercentage(); break;
            case 9: printf("\nExiting program. Goodbye!\n"); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}

/* ---------- Menu Display ---------- */
void showMenu() {
    printf("\n========================================\n");
    printf("   STUDENT RESULT MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Calculate Results (Total, %%, Grade)\n");
    printf("7. Topper Report\n");
    printf("8. Sort by Percentage (Descending)\n");
    printf("9. Exit\n");
    printf("Enter your choice : ");
}

/* ---------- Add Student ---------- */
void addStudent() {
    if (n >= MAX) {
        printf("\nStudent list is full!\n");
        return;
    }

    printf("\nEnter Roll Number      : ");
    scanf("%d", &rollNo[n]);
    printf("Enter Name             : ");
    scanf(" %[^\n]", names[n]);
    printf("Enter Marks (3 subjects) : ");
    scanf("%f %f %f", &marks[n][0], &marks[n][1], &marks[n][2]);

    n++;
    printf("\nStudent added successfully!\n");
}

/* ---------- Display All Students ---------- */
void displayAll() {
    int i;

    if (n == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n%-8s %-18s %-22s %-8s %-8s %-6s\n",
           "Roll", "Name", "Marks(S1,S2,S3)", "Total", "Perc%", "Grade");
    printf("-------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-8d %-18s %5.1f %5.1f %5.1f      %-8.1f %-8.2f %-6c\n",
               rollNo[i], names[i],
               marks[i][0], marks[i][1], marks[i][2],
               total[i], percentage[i], grade[i] == '\0' ? '-' : grade[i]);
    }
}

/* ---------- Search Student ---------- */
void searchStudent() {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to search : ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++) {
        if (rollNo[i] == roll) {
            printf("\nRecord Found:\n");
            printf("Roll No    : %d\n", rollNo[i]);
            printf("Name       : %s\n", names[i]);
            printf("Marks      : %.1f %.1f %.1f\n", marks[i][0], marks[i][1], marks[i][2]);
            printf("Total      : %.1f\n", total[i]);
            printf("Percentage : %.2f\n", percentage[i]);
            printf("Grade      : %c\n", grade[i] == '\0' ? '-' : grade[i]);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nStudent with Roll Number %d not found.\n", roll);
}

/* ---------- Update Student ---------- */
void updateStudent() {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to update : ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++) {
        if (rollNo[i] == roll) {
            printf("Enter new Name             : ");
            scanf(" %[^\n]", names[i]);
            printf("Enter new Marks (3 subjects) : ");
            scanf("%f %f %f", &marks[i][0], &marks[i][1], &marks[i][2]);
            printf("\nRecord updated successfully! (Run option 6 to refresh results)\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nStudent with Roll Number %d not found.\n", roll);
}

/* ---------- Delete Student ---------- */
void deleteStudent() {
    int roll, i, j, found = 0;

    printf("\nEnter Roll Number to delete : ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++) {
        if (rollNo[i] == roll) {
            for (j = i; j < n - 1; j++) {
                rollNo[j] = rollNo[j + 1];
                strcpy(names[j], names[j + 1]);
                marks[j][0] = marks[j + 1][0];
                marks[j][1] = marks[j + 1][1];
                marks[j][2] = marks[j + 1][2];
                total[j]      = total[j + 1];
                percentage[j] = percentage[j + 1];
                grade[j]      = grade[j + 1];
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

/* ---------- Calculate Total, Percentage, Grade ---------- */
void calculateResults() {
    int i;

    if (n == 0) {
        printf("\nNo records found.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        total[i]      = marks[i][0] + marks[i][1] + marks[i][2];
        percentage[i] = total[i] / 3;
        grade[i]      = calculateGrade(percentage[i]);
    }

    printf("\nResults calculated successfully for all students!\n");
}

/* ---------- Grade Calculation Function ---------- */
char calculateGrade(float perc) {
    if (perc >= 90)
        return 'A';
    else if (perc >= 75)
        return 'B';
    else if (perc >= 60)
        return 'C';
    else if (perc >= 40)
        return 'D';
    else
        return 'F';
}

/* ---------- Topper Report ---------- */
void topperReport() {
    int i, maxIndex;

    if (n == 0) {
        printf("\nNo records found.\n");
        return;
    }

    maxIndex = 0;
    for (i = 1; i < n; i++) {
        if (percentage[i] > percentage[maxIndex])
            maxIndex = i;
    }

    printf("\n--- Topper of the Class ---\n");
    printf("Roll No    : %d\n", rollNo[maxIndex]);
    printf("Name       : %s\n", names[maxIndex]);
    printf("Percentage : %.2f\n", percentage[maxIndex]);
    printf("Grade      : %c\n", grade[maxIndex]);
}

/* ---------- Sort by Percentage (Descending) ---------- */
void sortByPercentage() {
    int i, j;

    if (n == 0) {
        printf("\nNo records found.\n");
        return;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (percentage[j] < percentage[j + 1]) {
                // Swap roll number
                int tempRoll = rollNo[j];
                rollNo[j] = rollNo[j + 1];
                rollNo[j + 1] = tempRoll;

                // Swap name
                char tempName[50];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);

                // Swap marks
                float tempMarks;
                for (int k = 0; k < 3; k++) {
                    tempMarks = marks[j][k];
                    marks[j][k] = marks[j + 1][k];
                    marks[j + 1][k] = tempMarks;
                }

                // Swap total, percentage, grade
                float tempTotal = total[j];
                total[j] = total[j + 1];
                total[j + 1] = tempTotal;

                float tempPerc = percentage[j];
                percentage[j] = percentage[j + 1];
                percentage[j + 1] = tempPerc;

                char tempGrade = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = tempGrade;
            }
        }
    }

    printf("\nStudents sorted by percentage (Descending)!\n");
    displayAll();
}