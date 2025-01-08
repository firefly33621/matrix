#include <stdio.h>
#include <stdlib.h>

// 矩阵相乘函数
void multiplyMatrices(double** matrix1, double** matrix2, double** result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// 打印矩阵函数
void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("输入第一个矩阵的行数和列数: ");
    scanf_s("%d %d", &rows1, &cols1);

    printf("输入第二个矩阵的行数和列数: ");
    scanf_s("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("矩阵无法相乘，第一个矩阵的列数必须等于第二个矩阵的行数。\n");
        return 1;
    }

    double** matrix1 = (double**)malloc(rows1 * sizeof(double*));
    double** matrix2 = (double**)malloc(rows2 * sizeof(double*));
    double** result = (double**)malloc(rows1 * sizeof(double*));

    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (double*)malloc(cols1 * sizeof(double));
        result[i] = (double*)malloc(cols2 * sizeof(double));
    }

    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (double*)malloc(cols2 * sizeof(double));
    }

    printf("输入第一个矩阵的元素:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf_s("%lf", &matrix1[i][j]);
        }
    }

    printf("输入第二个矩阵的元素:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf_s("%lf", &matrix2[i][j]);
        }
    }

    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);

    printf("结果矩阵:\n");
    printMatrix(result, rows1, cols2);

    // 释放内存
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}