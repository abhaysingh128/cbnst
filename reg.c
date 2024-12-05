#include <stdio.h>

int main() {
    int n, i, j;
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, a, b;

    printf("Enter the number of observations: ");
    scanf("%d", &n);

    float x[n], y[n], augmented_matrix[2][3];

    printf("Enter values of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter values of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    for (i = 0; i < n; i++) {
        sum1 += x[i];          // Sx
        sum2 += y[i];          // Sy
        sum3 += x[i] * y[i];   // Sxy
        sum4 += x[i] * x[i];   // Sx^2
    }


    augmented_matrix[0][0] = n;
    augmented_matrix[0][1] = sum1;
    augmented_matrix[0][2] = sum2;
    augmented_matrix[1][0] = sum1;
    augmented_matrix[1][1] = sum4;
    augmented_matrix[1][2] = sum3;

    // Performing row operations to form the upper triangular matrix
    float ratio = augmented_matrix[1][0] / augmented_matrix[0][0];
    for (i = 0; i < 3; i++) {
        augmented_matrix[1][i] -= ratio * augmented_matrix[0][i];
    }

    printf("\nThe Upper Triangular Matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%.2f ", augmented_matrix[i][j]);
        }
        printf("\n");
    }

    b = augmented_matrix[1][2] / augmented_matrix[1][1];
    a = (augmented_matrix[0][2] - augmented_matrix[0][1] * b) / augmented_matrix[0][0];

    printf("\nSummations:\n");
    printf("Sx = %.2f\n", sum1);
    printf("Sy = %.2f\n", sum2);
    printf("Sxy = %.2f\n", sum3);
    printf("Sx^2 = %.2f\n", sum4);

    printf("\nIntercept (a) = %.2f\n", a);
    printf("Slope (b) = %.2f\n", b);

    printf("\nEquation of the line: y = %.2f + %.2fx\n", a, b);

    return 0;
}