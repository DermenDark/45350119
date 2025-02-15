#include <iostream>
#include <cmath>
#include <locale.h>
#include "../Static/bibl.h"

void rrr() {
    long double m = 0, D = 0;
    int n = 0;
    std::cout << "Введите размер массива:";
    std::cin >> n;

    m = prozessing(n);
    D = computeDispersion(n, m);

    std::cout << " Математическое ожидание:" << m << '\n' << "Дисперсия:" << D;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char otvet;
    std::cout << "Составить программу для вычисления математического ожидания m и дисперсии D.\n\nВыполнил задание номер 1:Ширко Владимир.\nВариант-№4(19 в списке)\n";

    do {
        rrr();

        std::cout << "\nХотите ввести еще один размер массива? \n(y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();

    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}
