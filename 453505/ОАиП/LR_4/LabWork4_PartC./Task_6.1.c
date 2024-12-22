#include <stdio.h>
#include <stdlib.h>

void printMatrix(long long** matrix, long long size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%lld ", matrix[row][col]);
        }
        printf("\n");
    }
}

void fillOddMagicSquare(long long** matrix, long long size, long long startVal, long long maxVal) {
    long long row = 0;
    long long col = size / 2;
    while (startVal <= maxVal) {
        matrix[row][col] = startVal++;
        long long prevRow = row;
        long long prevCol = col;
        col++;
        row--;
        if (row < 0 && col < size) row = size - 1;
        if (row >= 0 && col >= size) col = 0;
        if (row < 0 && col >= size) {
            row += 2;
            col--;
        }
        if (matrix[row][col] != 0) {
            row = prevRow;
            col = prevCol;
            row++;
        }
    }
}

void fillDoublyEvenMagicSquare(long long size) {
    long long** matrix = (long long**)malloc(size * sizeof(long long*));
    for (long long i = 0; i < size; ++i) {
        matrix[i] = (long long*)malloc(size * sizeof(long long));
        for (long long j = 0; j < size; j++) {
            matrix[i][j] = size * i + j + 1;
        }
    }

    for (long long i = 0; i < size / 4; i++) {
        for (int j = 0; j < size / 4; j++) {
            matrix[i][j] = size * size - (size * i + j);
            matrix[i + size / 4 * 3][j] = size * size - ((i + size / 4 * 3) * size + j);
            matrix[i][j + size / 4 * 3] = size * size - (size * i + j + size / 4 * 3);
            matrix[i + size / 4 * 3][j + size / 4 * 3] = size * size - ((i + size / 4 * 3) * size + j + size / 4 * 3);
        }
    }

    for (int i = size / 4; i < size / 4 * 3; i++) {
        for (int j = size / 4; j < size / 4 * 3; j++) {
            matrix[i][j] = size * size - (size * i + j);
        }
    }

    printMatrix(matrix, size);
    for (long long i = 0; i < size; ++i) free(matrix[i]);
    free(matrix);
}

void fillSinglyEvenMagicSquare(long long size) {
    long long halfSize = size / 2;
    long long subSquareSize = size * size / 4;

    long long** A = (long long**)malloc(halfSize * sizeof(long long*));
    long long** B = (long long**)malloc(halfSize * sizeof(long long*));
    long long** C = (long long**)malloc(halfSize * sizeof(long long*));
    long long** D = (long long**)malloc(halfSize * sizeof(long long*));

    for (long long i = 0; i < halfSize; ++i) {
        A[i] = (long long*)malloc(halfSize * sizeof(long long));
        B[i] = (long long*)malloc(halfSize * sizeof(long long));
        C[i] = (long long*)malloc(halfSize * sizeof(long long));
        D[i] = (long long*)malloc(halfSize * sizeof(long long));
    }

    fillOddMagicSquare(A, halfSize, 1, subSquareSize);
    fillOddMagicSquare(B, halfSize, 2 * subSquareSize + 1, 3 * subSquareSize);
    fillOddMagicSquare(C, halfSize, 3 * subSquareSize + 1, 4 * subSquareSize);
    fillOddMagicSquare(D, halfSize, subSquareSize + 1, 2 * subSquareSize);

    for (int row = 0; row < halfSize; row++) {
        for (int col = 0; col < size / 4; col++) {
            if (col < size / 4 - 1) {
                long long temp = B[row][halfSize - col - 1];
                B[row][halfSize - col - 1] = D[row][halfSize - col - 1];
                D[row][halfSize - col - 1] = temp;
            }
            if (row == size / 4 && col == 0) {
                long long temp = A[row][size / 4];
                A[row][size / 4] = C[row][size / 4];
                C[row][size / 4] = temp;
                continue;
            }
            long long temp = A[row][col];
            A[row][col] = C[row][col];
            C[row][col] = temp;
        }
    }

    for (int row = 0; row < halfSize; row++) {
        for (int col = 0; col < halfSize; col++) {
            printf("%lld ", A[row][col]);
        }
        for (int col = 0; col < halfSize; col++) {
            printf("%lld ", B[row][col]);
        }
        printf("\n");
    }
    for (int row = 0; row < halfSize; row++) {
        for (int col = 0; col < halfSize; col++) {
            printf("%lld ", C[row][col]);
        }
        for (int col = 0; col < halfSize; col++) {
            printf("%lld ", D[row][col]);
        }
        printf("\n");
    }

    for (long long i = 0; i < halfSize; ++i) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
        free(D[i]);
    }
    free(A);
    free(B);
    free(C);
    free(D);
}

void generateMagicSquare(long long size) {
    if (size % 2 == 1) {
        long long** matrix = (long long**)malloc(size * sizeof(long long*));
        for (long long i = 0; i < size; ++i) {
            matrix[i] = (long long*)malloc(size * sizeof(long long));
            for (int j = 0; j < size; j++) matrix[i][j] = 0;
        }
        fillOddMagicSquare(matrix, size, 1, size * size);
        printMatrix(matrix, size);
        for (long long i = 0; i < size; ++i) free(matrix[i]);
        free(matrix);
    } else if (size % 4 == 0) {
        fillDoublyEvenMagicSquare(size);
    } else {
        fillSinglyEvenMagicSquare(size);
    }
}

void square() {
    printf("Введите длину стороны квадрата:\n");
    long long size;
    scanf("%lld", &size);
    if (size == 1) {
        printf("1\n");
        return ;
    }
    if (size == 2) {
        printf("NO\n");
        return ;
    }
    generateMagicSquare(size);
}
int main() {
    char otvet;
    printf("маг квадрат.\n");
    printf("Выполнил задание: Ширко Владимир.\n");

    do {
        square();

        printf("\nХотите создать ещё магический квадрат? (y-да/n-нет): ");
        scanf(" %c", &otvet); 

    } while (otvet == 'y' || otvet == 'Y');

    printf("Программа завершена.\n");
    
    return 0;
}