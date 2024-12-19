#include <iostream>
#include <vector>
#include <algorithm>

#define ld long double

ld glav_proz(std::vector<ld>& X) {
    int a = 0, B = 0, proisv = 1;
    std::vector<ld> Y(B);

    for (int i = 0; i < X.size(); ++i) {
            if (X[i] == 0) {
                Y.push_back(i);
                ++a;
            }
    }

    std::reverse(X.begin(), X.end());

    std::cout << '\n'<<"Перевернутый изначальный массив:";
    for (int i = 0; i < X.size(); ++i) {
        std::cout << "X[" << i << "]" << X[i] << ' ';
    }


    std::cout << '\n'<<"Индексы нулевых значений:";
    for (int i = 0; i < Y.size(); ++i) {
        std::cout << "X[" << Y[i] << "]=" << 0 << ' ';
    }
    return a;
}
void glavn() {
    std::cout << "Программа завершена.\n";

    int N = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> N;

    std::vector<ld> X(N);
    std::cout << "Введите элементы массива:\n";

    for (int i = 0; i < N; ++i) {
        std::cout << "Введите элемент X[" << i << "]: ";
        std::cin >> X[i];
        if (std::cin.fail()) {
            std::cout << "\nНеверно введённый элемент в позиции X[" << i << "]\n";
            return;
        }
    }

    long double M = glav_proz(X);
    std::cout << "\nКолличество нулей: " << M << std::endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    char otvet;
    std::cout << "Создать двумерный динамический массив вещественных чисел. \nОпределить, встречаются ли среди них элементы с нулевым значением.Если встречаются такие элементы,\n то определить их индексы и общее количество.\n\nВыполнил задание номер 4:Ширко Владимир.\n";

    do {
        glavn();

        std::cout << "\nХотите ввести еще один размер массива? \n(y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();

    } while (otvet == 'y' || otvet == 'Y');
    std::cout << "Программа завершена.\n";
    return 0;
}