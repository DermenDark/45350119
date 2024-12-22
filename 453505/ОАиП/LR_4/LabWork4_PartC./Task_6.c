#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>

typedef int ll; 
int TEST_OUT = 0;

int TestMagicSquare(int size, int *square) {
    int sumi = 0;
    int sumj = 0;
    int sumDik = 0;
    int sumlak = 0;
    int magsum = size * (size * size + 1) / 2;

    for (int i = 0; i < size; ++i) {
        sumi = 0, sumj = 0;
        for (int j = 0; j < size; ++j) {
            sumi += square[i * size + j]; 
            sumj += square[j * size + i]; 
        }
        sumDik += square[i * size + i]; 
        sumlak += square[i * size + (size - i - 1)]; 

        if (sumi != magsum || sumj != magsum) {
            return 1; 
        }
    }
    
    if (sumDik != magsum || sumlak != magsum) {
        return 1; 
    }

    return 1; 
}
TEST(TestSquare, TestMagicSquare) {
    EXPECT_EQ(0, TEST_OUT);
}

void print_square(int** matrix, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void fill_magic_square(int** matrix, int size, int start_val, int end_val) {
    int i = 0, j = size / 2;
    while (start_val <= end_val) {
        matrix[i][j] = start_val++;
        
        int temp_i = i, temp_j = j;
        i--; j++;

        if (i < 0 && j < size) i = size - 1;
        if (i >= 0 && j >= size) j = 0;
        if (i < 0 && j >= size) {
            i += 2;
            j--;
        }

        if (matrix[i][j] != 0) {
            i = temp_i;
            j = temp_j;
            i++;
        }
    }
}

void generate_magic_square(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = size * i + j + 1;
        }
    }

    for (int i = 0; i < size / 4; i++) {
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

    print_square(matrix, size);

    for (int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void generate_square(int size) {
    int quarter_size = size * size / 4;

    int** matrix_a = (int**)malloc(size / 2 * sizeof(int*));
    int** matrix_b = (int**)malloc(size / 2 * sizeof(int*));
    int** matrix_c = (int**)malloc(size / 2 * sizeof(int*));
    int** matrix_d = (int**)malloc(size / 2 * sizeof(int*));

    for (int i = 0; i < size / 2; ++i) {
        matrix_a[i] = (int*)malloc(size / 2 * sizeof(int));
        matrix_b[i] = (int*)malloc(size / 2 * sizeof(int));
        matrix_c[i] = (int*)malloc(size / 2 * sizeof(int));
        matrix_d[i] = (int*)malloc(size / 2 * sizeof(int));
    }

    fill_magic_square(matrix_a, size / 2, 1, quarter_size);
    fill_magic_square(matrix_b, size / 2, quarter_size + 1, 2 * quarter_size);
    fill_magic_square(matrix_c, size / 2, 2 * quarter_size + 1, 3 * quarter_size);
    fill_magic_square(matrix_d, size / 2, 3 * quarter_size + 1, 4 * quarter_size);

    for (int i = 0; i < size / 2; i++) {
        for (int j = 0; j < size / 2; j++) {
            printf("%d ", matrix_a[i][j]);
        }
        for (int j = 0; j < size / 2; j++) {
            printf("%d ", matrix_b[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size / 2; i++) {
        for (int j = 0; j < size / 2; j++) {
            printf("%d ", matrix_c[i][j]);
        }
        for (int j = 0; j < size / 2; j++) {
            printf("%d ", matrix_d[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size / 2; ++i) {
        free(matrix_a[i]);
        free(matrix_b[i]);
        free(matrix_c[i]);
        free(matrix_d[i]);
    }
    free(matrix_a);
    free(matrix_b);
    free(matrix_c);
    free(matrix_d);
}

void create_magic_square() {
    int size;
    printf("Введите размер маг.квадрата: ");
    scanf("%d", &size);
    
    if (size == 1) {
        printf("1\n");
        return;
    }

    if (size == 2) {
        printf("NO\n");
        return;
    }

    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }

    if (size % 2 == 1) {
        fill_magic_square(matrix, size, 1, size * size);
    } else if (size % 4 == 0) {
        generate_magic_square(size);
    } else {
        generate_square(size);
    }

    print_square(matrix, size);

    int* flat_matrix = (int*)malloc( size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            flat_matrix[i * size + j] = matrix[i][j];
        }
    }

    int TEST_OUT = TestMagicSquare(size, flat_matrix);
    free(flat_matrix);
    RUN_ALL_TESTS();

    for (int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    char otvet;
    printf("Нмаг квадрат.\n");
    printf("Выполнил задание: Ширко Владимир.\n");

    do {
        create_magic_square();

        printf("\nХотите ввести еще хотите создать магический квадрат? (y-да/n-нет): ");
        scanf(" %c", &otvet); 

    } while (otvet == 'y' || otvet == 'Y');

    printf("Программа завершена.\n");
    
    return 0;
}