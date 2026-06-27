#include <stdio.h>

int main() {
    char name[50];
    int roll;
    float m1, m2, m3, m4, m5;
    float total, percentage;

    printf("Enter Student Name: ");
    scanf("%s", name);

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Marks of 5 Subjects:\n");
    scanf("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);

    total = m1 + m2 + m3 + m4 + m5;
    percentage = total / 5;

    printf("\n===== MARKSHEET =====\n");
    printf("Name       : %s\n", name);
    printf("Roll No.   : %d\n", roll);
    printf("Total Marks: %.2f/500\n", total);
    printf("Percentage : %.2f%%\n", percentage);

    if(percentage >= 90)
        printf("Grade : A+\n");
    else if(percentage >= 80)
        printf("Grade : A\n");
    else if(percentage >= 70)
        printf("Grade : B\n");
    else if(percentage >= 60)
        printf("Grade : C\n");
    else if(percentage >= 40)
        printf("Grade : D\n");
    else
        printf("Grade : F\n");

    if(percentage >= 40)
        printf("Result : PASS\n");
    else
        printf("Result : FAIL\n");

    return 0;
}