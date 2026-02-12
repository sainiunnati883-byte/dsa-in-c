#include <stdio.h>

int main() {
    int m, n;
    int matrix[20][20];
    int isSymmetric = 1;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    printf("Enter matrix elements row-wise:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }

    if (isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}

