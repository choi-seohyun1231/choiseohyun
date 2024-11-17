#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100

void input2DArray(int array[][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = rand() % 10 + 1; // 1~10 사이의 랜덤 값
        }
    }
}

void print2DArray(int array[][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("[%4d] ", array[i][j]);
        }
        printf("\n");
    }
    printf("=======================\n");
}

void multiplyMatrix(int s1[][COL], int s2[][COL], int result[][COL], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += s1[i][k] * s2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    int result[ROW][COL];

    int row1 = 5, col1 = 2; // 첫 번째 행렬 크기 (5x2)
    int row2 = 2, col2 = 10; // 두 번째 행렬 크기 (2x10)

    srand(time(NULL));

    // 행렬 생성 및 출력
    input2DArray(matrix1, row1, col1);
    input2DArray(matrix2, row2, col2);

    printf("Matrix 1 (5x2):\n");
    print2DArray(matrix1, row1, col1);

    printf("Matrix 2 (2x10):\n");
    print2DArray(matrix2, row2, col2);

    // 행렬 곱셈
    multiplyMatrix(matrix1, matrix2, result, row1, col1, col2);

    // 결과 출력
    printf("Result (Matrix 1 * Matrix 2):\n");
    print2DArray(result, row1, col2);

    return 0;
}
