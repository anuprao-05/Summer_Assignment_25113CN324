#include <stdio.h>

int main() {
    int choice, i;
    float num1, num2, result;
    int a, b, power, base, exp;

    do {
        printf("\n========================================\n");
        printf("   MENU-DRIVEN CALCULATOR\n");
        printf("========================================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power (x^n)\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter two numbers : ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("Result = %.2f\n", result);
        }

        else if (choice == 2) {
            printf("\nEnter two numbers : ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("Result = %.2f\n", result);
        }

        else if (choice == 3) {
            printf("\nEnter two numbers : ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("Result = %.2f\n", result);
        }

        else if (choice == 4) {
            printf("\nEnter two numbers : ");
            scanf("%f %f", &num1, &num2);
            if (num2 == 0)
                printf("Error: Division by zero not allowed!\n");
            else {
                result = num1 / num2;
                printf("Result = %.2f\n", result);
            }
        }

        else if (choice == 5) {
            printf("\nEnter two integers : ");
            scanf("%d %d", &a, &b);
            if (b == 0)
                printf("Error: Modulus by zero not allowed!\n");
            else
                printf("Result = %d\n", a % b);
        }

        else if (choice == 6) {
            printf("\nEnter base and exponent : ");
            scanf("%d %d", &base, &exp);
            power = 1;
            for (i = 1; i <= exp; i++)
                power = power * base;
            printf("Result = %d\n", power);
        }

        else if (choice == 7) {
            printf("\nExiting calculator. Goodbye!\n");
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}