#include <stdio.h>
#include <string.h>

#define MAX 100

struct Account {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct Account accounts[MAX];
    int n = 0;
    int choice, i, j, accNo, found;
    float amount;

    do {
        printf("\n========================================\n");
        printf("   BANK ACCOUNT MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Check Balance\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n >= MAX) {
                printf("\nAccount list is full!\n");
            } else {
                printf("\nEnter Account Number : ");
                scanf("%d", &accounts[n].accNo);
                printf("Enter Name           : ");
                scanf(" %[^\n]", accounts[n].name);
                printf("Enter Initial Deposit : ");
                scanf("%f", &accounts[n].balance);
                n++;
                printf("\nAccount created successfully!\n");
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("\nNo accounts found.\n");
            } else {
                printf("\n%-15s %-20s %-15s\n", "Account No", "Name", "Balance");
                printf("------------------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%-15d %-20s %-15.2f\n", accounts[i].accNo, accounts[i].name, accounts[i].balance);
                }
            }
        }

        else if (choice == 3) {
            printf("\nEnter Account Number : ");
            scanf("%d", &accNo);
            found = 0;
            for (i = 0; i < n; i++) {
                if (accounts[i].accNo == accNo) {
                    printf("Enter amount to deposit : ");
                    scanf("%f", &amount);
                    accounts[i].balance = accounts[i].balance + amount;
                    printf("\nAmount deposited successfully!\n");
                    printf("New Balance = %.2f\n", accounts[i].balance);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nAccount with number %d not found.\n", accNo);
        }

        else if (choice == 4) {
            printf("\nEnter Account Number : ");
            scanf("%d", &accNo);
            found = 0;
            for (i = 0; i < n; i++) {
                if (accounts[i].accNo == accNo) {
                    found = 1;
                    printf("Enter amount to withdraw : ");
                    scanf("%f", &amount);

                    if (amount > accounts[i].balance) {
                        printf("\nInsufficient balance!\n");
                        printf("Available Balance = %.2f\n", accounts[i].balance);
                    } else {
                        accounts[i].balance = accounts[i].balance - amount;
                        printf("\nAmount withdrawn successfully!\n");
                        printf("New Balance = %.2f\n", accounts[i].balance);
                    }
                    break;
                }
            }
            if (found == 0)
                printf("\nAccount with number %d not found.\n", accNo);
        }

        else if (choice == 5) {
            printf("\nEnter Account Number : ");
            scanf("%d", &accNo);
            found = 0;
            for (i = 0; i < n; i++) {
                if (accounts[i].accNo == accNo) {
                    printf("\nAccount Holder : %s\n", accounts[i].name);
                    printf("Current Balance = %.2f\n", accounts[i].balance);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nAccount with number %d not found.\n", accNo);
        }

        else if (choice == 6) {
            printf("\nEnter Account Number to delete : ");
            scanf("%d", &accNo);
            found = 0;
            for (i = 0; i < n; i++) {
                if (accounts[i].accNo == accNo) {
                    for (j = i; j < n - 1; j++) {
                        accounts[j] = accounts[j + 1];
                    }
                    n--;
                    printf("\nAccount deleted successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nAccount with number %d not found.\n", accNo);
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