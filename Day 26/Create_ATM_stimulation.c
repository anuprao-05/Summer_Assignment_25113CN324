#include <stdio.h>

int main() {
    int choice;
    float balance = 10000, amount;

    do {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Current Balance = %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if(amount > 0) {
                    balance += amount;
                    printf("Deposit Successful.\n");
                    printf("Updated Balance = %.2f\n", balance);
                }
                else
                    printf("Invalid Amount!\n");

                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if(amount <= balance && amount > 0) {
                    balance -= amount;
                    printf("Withdrawal Successful.\n");
                    printf("Remaining Balance = %.2f\n", balance);
                }
                else
                    printf("Insufficient Balance or Invalid Amount!\n");

                break;

            case 4:
                printf("Thank You for Using ATM.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}