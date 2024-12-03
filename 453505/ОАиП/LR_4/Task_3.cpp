#include <iostream>
#include <cmath>
#include <algorithm>

double max_Row(long double* row, int m) {
    double max_value = row[0];
    for (int i = 1; i < m; ++i) {
        if (row[i] > max_value) {
            max_value = row[i];
        }
    }
    return max_value;
}

void maxEl(long double** matrix, int n, int m) {
    // Сортируем строки матрицы по максимальным элементам
    std::sort(matrix, matrix + n, [m](long double* a, long double* b) {
        return max_Row(a, m) > max_Row(b, m);
    });
}

void matrik() {
    long long int n, m;

    std::cout << "Введите количество строк (N): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (M): ";
    std::cin >> m;

    long double** arr = new long double*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new long double[m];
    }

    std::cout << "\nВведите матрицу чисел (разделяйте числа пробелами): ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> arr[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int f = 0; f < m; ++f) {
            if (std::isnan(arr[k][f])) {
                std::cout << "\nНеверно введённа матрица.\n[" << k << "] и [" << f << "] - номер вводимого элемента, с которым возникли трудности.";
                for (int i = 0; i < n; ++i) {
                    delete[] arr[i];
                }
                delete[] arr;
                return;
            }
        }
    }

    maxEl(arr, n, m);

    std::cout << "Упорядоченная матрица: ";
    for (int k = 0; k < n; ++k) {
        std::cout << "\n";
        for (int f = 0; f < m; ++f) {
            std::cout << arr[k][f] << " ";
        }
    }

    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return;
}

int main() {
    char otvet;
    std::cout << "Необходимо упорядочить строки матрицы по возрастанию наибольших элементов в её строках.\nВыполнил задание №3: Ширко Владимир.\nВариант-№4(19 в списке)\n";
    do {
        matrik();
        std::cout << "\nХотите ввести еще один массив чисел? (y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}