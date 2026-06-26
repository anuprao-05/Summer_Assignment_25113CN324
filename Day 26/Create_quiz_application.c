#include <stdio.h>

int main() {
    int choice, score = 0;

    printf("===== C QUIZ =====\n\n");

    printf("Q1. Who developed C language?\n");
    printf("1. Dennis Ritchie\n");
    printf("2. James Gosling\n");
    printf("3. Bjarne Stroustrup\n");
    printf("4. Guido van Rossum\n");
    printf("Enter your answer: ");
    scanf("%d", &choice);

    if(choice == 1)
        score++;

    printf("\nQ2. Which symbol is used to end a C statement?\n");
    printf("1. :\n");
    printf("2. ;\n");
    printf("3. .\n");
    printf("4. ,\n");
    printf("Enter your answer: ");
    scanf("%d", &choice);

    if(choice == 2)
        score++;

    printf("\nQ3. Which loop is guaranteed to execute at least once?\n");
    printf("1. for\n");
    printf("2. while\n");
    printf("3. do-while\n");
    printf("4. None\n");
    printf("Enter your answer: ");
    scanf("%d", &choice);

    if(choice == 3)
        score++;

    printf("\nQ4. Which header file is used for printf()?\n");
    printf("1. math.h\n");
    printf("2. string.h\n");
    printf("3. stdio.h\n");
    printf("4. conio.h\n");
    printf("Enter your answer: ");
    scanf("%d", &choice);

    if(choice == 3)
        score++;

    printf("\nQ5. C is a ______ language.\n");
    printf("1. High-level\n");
    printf("2. Middle-level\n");
    printf("3. Assembly\n");
    printf("4. Machine\n");
    printf("Enter your answer: ");
    scanf("%d", &choice);

    if(choice == 2)
        score++;

    printf("\n=====================\n");
    printf("Your Score = %d/5\n", score);

    if(score == 5)
        printf("Excellent!\n");
    else if(score >= 3)
        printf("Good Job!\n");
    else
    
        printf("Keep Practicing!\n");

    return 0;
}