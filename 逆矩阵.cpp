#include <stdio.h>
#include <stdlib.h>

// ������˺���
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

// ��ӡ������
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

    printf("�����һ�����������������: ");
    scanf_s("%d %d", &rows1, &cols1);

    printf("����ڶ������������������: ");
    scanf_s("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("�����޷���ˣ���һ�����������������ڵڶ��������������\n");
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

    printf("�����һ�������Ԫ��:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf_s("%lf", &matrix1[i][j]);
        }
    }

    printf("����ڶ��������Ԫ��:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf_s("%lf", &matrix2[i][j]);
        }
    }

    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);

    printf("�������:\n");
    printMatrix(result, rows1, cols2);

    // �ͷ��ڴ�
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