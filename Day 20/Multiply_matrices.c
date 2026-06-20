#include <stdio.h>

int main() {
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows and columns of First Matrix  : ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Second Matrix : ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("\nMatrix multiplication not possible!\n");
        printf("(Columns of First Matrix must equal Rows of Second Matrix)\n");
        return 1;
    }

    int A[r1][c1], B[r2][c2], C[r1][c2];

    printf("\nEnter elements of First Matrix (%dx%d) :\n", r1, c1);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("A[%d][%d] : ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Second Matrix (%dx%d) :\n", r2, c2);
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("B[%d][%d] : ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Multiply matrices
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (k = 0; k < c1; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix (%dx%d) :\n", r1, c2);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}