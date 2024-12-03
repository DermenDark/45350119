#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Введите размерность n: ");
    scanf("%d", &n);

    // Создание трёхмерного динамического массива
    int ***array = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++) {
        array[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            array[i][j] = (int *)malloc(n * sizeof(int));
        }
    }

    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("array[%d][%d][%d] = ", i, j, k);
                scanf("%d", &array[i][j][k]);
            }
        }
    }

    // Инициализация переменных для нахождения диагонали с максимальной суммой
    int max_sum = 0;
    int max_index = -1;

    // Обход диагоналей
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = 0; j < n; j++) {
            current_sum += array[i][j][j]; // Пример для одной диагонали
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_index = i;
        }
    }

    // Вывод результата
    printf("Индекс диагонали с наибольшей суммой: %d\n", max_index);
    printf("Сумма элементов диагонали: %d\n", max_sum);

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);

    return 0;
}