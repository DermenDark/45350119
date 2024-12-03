#include <stdio.h>

#define MAX_N 100
#define MAX_M 100

void create_minesweeper_field(int n, int m, char field[MAX_N][MAX_M], char output_field[MAX_N][MAX_M]) {
    // Определяем направления для соседей (всего 8 направлений)
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    // Проходим по каждой ячейке поля
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                // Если это бомба, оставляем её в выходном поле
                output_field[i][j] = '*';
                
                // Увеличиваем счетчик бомб вокруг соседей
                for (int k = 0; k < 8; k++) {
                    int ni = i + directions[k][0];
                    int nj = j + directions[k][1];
                    // Проверяем границы
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && field[ni][nj] == '.') {
                        if (output_field[ni][nj] == '.') {
                            output_field[ni][nj] = '0'; // Инициализируем как 0
                        }
                        output_field[ni][nj]++;
                    }
                }
            } else {
                output_field[i][j] = '.'; // Если это пустое место, оставляем точку
            }
        }
    }
}

void print_field(int n, int m, char field[MAX_N][MAX_M]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // количество строк
    int m = 5; // количество столбцов
    char field[MAX_N][MAX_M] = {
        {'.', '.', '*', '.', '.'},
        {'.', '*', '.', '*', '.'},
        {'.', '.', '.', '.', '.'},
        {'*', '.', '*', '.', '.'}
    };
    char output_field[MAX_N][MAX_M];

    create_minesweeper_field(n, m, field, output_field);
    print_field(n, m, output_field);

    return 0;
}