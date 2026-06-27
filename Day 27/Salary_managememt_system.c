#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basic, hra, da, gross;
};

int main() {
    struct Employee emp;
    float hraPercent = 20, daPercent = 10;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic);

    emp.hra = (hraPercent * emp.basic) / 100;
    emp.da = (daPercent * emp.basic) / 100;
    emp.gross = emp.basic + emp.hra + emp.da;

    printf("\n===== Salary Details =====\n");
    printf("Employee ID   : %d\n", emp.id);
    printf("Employee Name : %s\n", emp.name);
    printf("Basic Salary  : %.2f\n", emp.basic);
    printf("HRA (20%%)     : %.2f\n", emp.hra);
    printf("DA (10%%)      : %.2f\n", emp.da);
    printf("Gross Salary  : %.2f\n", emp.gross);

    return 0;
}