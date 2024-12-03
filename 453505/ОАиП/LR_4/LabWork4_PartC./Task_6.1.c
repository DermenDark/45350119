#include <stdio.h>
#include <stdlib.h>
#define ll long long

void printMatrix(ll** matrix, ll size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%lld ", matrix[row][col]);
        }
        printf("\n");
    }
}

void fillOddMagicSquare(ll** matrix, ll size, ll startVal, ll maxVal) {
    ll row = 0, col = size / 2;
    while (startVal <= maxVal) {
        matrix[row][col] = startVal++;
        ll prevRow = row, prevCol = col;
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

void fillDoublyEvenMagicSquare(ll size) {
    ll** matrix = (ll**)malloc(size * sizeof(ll*));
    for (ll i = 0; i < size; ++i) {
        matrix[i] = (ll*)malloc(size * sizeof(ll));
        for (ll j = 0; j < size; j++) {
            matrix[i][j] = size * i + j + 1;
        }
    }

    for (ll i = 0; i < size / 4; i++) {
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
    for (ll i = 0; i < size; ++i) free(matrix[i]);
    free(matrix);
}

void fillSinglyEvenMagicSquare(ll size) {
    ll halfSize = size / 2;
    ll subSquareSize = size * size / 4;

    ll** A = (ll**)malloc(halfSize * sizeof(ll*));
    ll** B = (ll**)malloc(halfSize * sizeof(ll*));
    ll** C = (ll**)malloc(halfSize * sizeof(ll*));
    ll** D = (ll**)malloc(halfSize * sizeof(ll*));

    for (ll i = 0; i < halfSize; ++i) {
        A[i] = (ll*)malloc(halfSize * sizeof(ll));
        B[i] = (ll*)malloc(halfSize * sizeof(ll));
        C[i] = (ll*)malloc(halfSize * sizeof(ll));
        D[i] = (ll*)malloc(halfSize * sizeof(ll));
    }

    fillOddMagicSquare(A, halfSize, 1, subSquareSize);
    fillOddMagicSquare(B, halfSize, 2 * subSquareSize + 1, 3 * subSquareSize);
    fillOddMagicSquare(C, halfSize, 3 * subSquareSize + 1, 4 * subSquareSize);
    fillOddMagicSquare(D, halfSize, subSquareSize + 1, 2 * subSquareSize);

    for (int row = 0; row < halfSize; row++) {
        for (int col = 0; col < size / 4; col++) {
            if (col < size / 4 - 1) {
                ll temp = B[row][halfSize - col - 1];
                B[row][halfSize - col - 1] = D[row][halfSize - col - 1];
                D[row][halfSize - col - 1] = temp;
            }
            if (row == size / 4 && col == 0) {
                ll temp = A[row][size / 4];
                A[row][size / 4] = C[row][size / 4];
                C[row][size / 4] = temp;
                continue;
            }
            ll temp = A[row][col];
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

    for (ll i = 0; i < halfSize; ++i) {
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

void generateMagicSquare(ll size) {
    if (size % 2 == 1) {
        ll** matrix = (ll**)malloc(size * sizeof(ll*));
        for (ll i = 0; i < size; ++i) {
            matrix[i] = (ll*)malloc(size * sizeof(ll));
            for (int j = 0; j < size; j++) matrix[i][j] = 0;
        }
        fillOddMagicSquare(matrix, size, 1, size * size);
        printMatrix(matrix, size);
        for (ll i = 0; i < size; ++i) free(matrix[i]);
        free(matrix);
    } else if (size % 4 == 0) {
        fillDoublyEvenMagicSquare(size);
    } else {
        fillSinglyEvenMagicSquare(size);
    }
}

void square() {
    printf("Введите длину стороны квадрата:\n");
    ll size;
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