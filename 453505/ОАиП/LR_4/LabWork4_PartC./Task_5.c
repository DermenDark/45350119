#include <stdio.h>
#include <stdlib.h>

void mirovanie(int n, int m, char field[n][m], char out_put[n][m]) {
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (field[i][j] == '*') {
            out_put[i][j] = '*';
        } else {
            out_put[i][j] = '0';
            for (int k = 0; k < 8; k++) {
                int ni = i + directions[k][0];
                int nj = j + directions[k][1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && field[ni][nj] == '*') {
                    out_put[i][j]++;
                }
            }
            if (out_put[i][j] == '0') {
                out_put[i][j] = '.';
            }
        }
    }
}
}

void print_field(int n, int m, char field[n][m]) {
    printf("Игровое поле:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}
void game(){
    long long int n, m;
    printf("Введите количество строк (N): ");
    scanf("%lld", &n); 
    printf("Введите количество столбцов (M): ");
    scanf("%lld", &m);

    char (*field)[m] = malloc(n * sizeof *field);
    char (*out_put)[m] = malloc(n * sizeof *out_put);


    if (field == NULL || out_put == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1; 
    }

    printf("Введите поле (используйте '*' для мин и '.' для пустых клеток):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &field[i][j]); 
        }
    }

    mirovanie(n, m, field, out_put);
    print_field(n, m, out_put);

    free(field);
    free(out_put);

    return;
}

int main() {
    char otvet;
    printf("На вход подаётся поле для игры в сапёр. Требуется дополнить это поле числами, как в оригинальной игре.\n");
    printf("\nВыполнил задание№5:Ширко Владимир.\nВариант-№5(19 в списке)\n");
    
    do {
        game();

        printf("\nХотите ввести еще одно поле? (y-да/n-нет): ");
        scanf(" %c", &otvet); 

    } while (otvet == 'y' || otvet == 'Y');

    printf("Программа завершена.\n");

    return 0;
}
