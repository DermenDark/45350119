#include <iostream>
#include <vector>
#include <algorithm>

#define li long int

li glav_diog(const std::vector< std::vector<li>>& X) {
    int B=0,proisv=1;
    bool found = false;
    std::vector<li> Y(B);

    for (int i = 0; i < X.size(); ++i) {
        for (int j = 0; j < X[i].size(); ++j) {
            if (i==j && X[i][j] % 2 == 0) {
                Y.push_back(X[i][j]);
                found = false;
            }
        }
    }
   
    if (!found) {
        std::cout << "На главной диагонали нет четных элементов.\n";
        return 0;
    }

    std::reverse(Y.begin(), Y.end());
    if (proisv == 1) { return 0; }
    for (int i = 0; i < Y.size(); ++i) {
        proisv *= Y[i];
        std::cout<<"Y[" <<i<<"]" << Y[i]<<'\n';
    }
    return proisv;
}

void osnova() {
    int N = 0, k = 0;
    bool validInput = false;


    while (!validInput) {
        std::cout << "\nВведите размеры массива (N x K): ";
        std::cin >> N >> k;

        if (N <= 0 || k <= 0) {
            std::cout << "\nНеверно введённые размеры. Размеры должны быть больше нуля.\n";
        }
        else if (std::cin.fail()) {
            std::cout << "\nНеверно введённые размеры.";
        }
        else {
            validInput = true; 
        }
    }

    std::vector< std::vector<li>> X(N, std::vector<li>(k));
    std::cout << "Введите элементы массива\n(если ввели нужный элемент, то жмите энтер):\n";

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << "Введите элемент X[" << i << "][" << j << "]: ";
            std::cin >> X[i][j];
            if (std::cin.fail()) {
                std::cout << "\nНеверно введённый элемент в позиции X[" << i << "][" << j << "]\n";
                return;
            }
        }
    }

    long double M = glav_diog(X);
    std::cout << "Произведение выбранных элементов: " << M << std::endl;
}
int main() {

    setlocale(LC_ALL, "Russian");

    char otvet;
    std::cout << "Создать динамический массив из элементов, расположенных на главной диагонали матрицы и имеющих четное значение.\nВычислить произведение элементов динамического массива.\n\nВыполнил задание:Ширко Владимир.\nВариант-№4(19 в списке)\n";

    do {
        osnova();
        std::cout << "\nХотите ввести еще один массив чисел? \n(y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}