#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int ***created(long long int x, long long int y, long long int z) {
    long long int ***array = (long long int ***)malloc(x * sizeof(long long int **));
    for (long long int i = 0; i < x; i++) {
        array[i] = (long long int **)malloc(y * sizeof(long long int *));
        for (long long int j = 0; j < y; j++) {
            array[i][j] = (long long int *)malloc(z * sizeof(long long int));
        }
    }
    return array;
}

void freeee(long long int ***array, long long int x, long long int y) {
    for (long long int i = 0; i < x; i++) {
        for (long long int j = 0; j < y; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}
void poisk(){long long int x, y, z;
    printf("Введите размеры массива (x, y, z): ");
    scanf("%lld %lld %lld", &x, &y, &z);

    if (x <= 0 || y <= 0 || z <= 0) {
        printf("Все размеры массива должны быть положительными.\n");
        return 1;
    }

    long long int ***array = created(x, y, z);

    printf("Вводите элементы массива:\n");
    for (long long int i = 0; i < x; i++) {
        for (long long int j = 0; j < y; j++) {
            for (long long int k = 0; k < z; k++) {
                scanf("%lld", &array[i][j][k]);
            }
        }
    }

    // srand(time(NULL));
    // for (long long int i = 0; i < x; i++) {
    //     for (long long int j = 0; j < y; j++) {
    //         for (long long int k = 0; k < z; k++) {
    //             array[i][j][k] = rand() % 10;
    //         }
    //     }
    // }

    printf("Массив:\n");
    for (long long int i = 0; i < x; i++) {
        for (long long int j = 0; j < y; j++) {
            for (long long int k = 0; k < z; k++) {
                printf("%lld ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    long long int max_sum = 0, max_diag_index = -1;
    long long int sums[4] = {0, 0, 0, 0};

    for (long long int i = 0; i < x && i < y && i < z; i++) {
        sums[0] += array[i][i][i]; // 1 диагональ
    }
    for (long long int i = 0; i < x && i < y && (z - i - 1) >= 0; i++) {
        sums[1] += array[i][i][z - i - 1]; // 2 диагональ
    }

    for (long long int i = 0; i < x && (y - i - 1) >= 0 && i < z; i++) {
        sums[2] += array[i][y - i - 1][i]; // 3 диагональ
    }

    for (long long int i = 0; (x - i - 1) >= 0 && i < y && i < z; i++) {
        sums[3] += array[x - i - 1][i][i]; // 4 диагональ
    }

    for (int d = 0; d < 4; d++) {
        if (sums[d] > max_sum) {
            max_sum = sums[d];
            max_diag_index = d;
        }
    }

    printf("Максимальная сумма: %lld на диагонали %lld\n", max_sum, max_diag_index + 1);

    freeee(array, x, y);
    return;
}

int main() {char otvet;

    printf("Необходимо определить диагональ с наибольшей суммой чисел.\n");
    printf("Выполнил задание: Ширко Владимир.\n");

    do {
        poisk();

        printf("\nХотите ввести еще один массив чисел? (y-да/n-нет): ");
        scanf(" %c", &otvet); 

    } while (otvet == 'y' || otvet == 'Y');

    printf("Программа завершена.\n");

    return 0;
}
