#include <iostream>
#include <cmath>

double coss(double x, int n) {
    double result = 1.0; 
    double term = 1.0;   

    for (int i = 1; i <= n; ++i) {
        term *= -x * x / ((2 * i - 1) * (2 * i)); 
        result += term; 
    }

    return result;
}

int main() {
    int n, m;


    std::cout << "Введите количество членов ряда (n): ";
    std::cin >> n;

    std::cout << "Введите количество значений x: ";
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        double x;
        std::cout << "Введите значение x (от 0.1 до 1): ";
        std::cin >> x;

        if (x < 0.1 || x > 1) {
            std::cerr << "Ошибка: x должно быть в диапазоне [0.1, 1]" << std::endl;
            continue;
        }

        double taylor = coss(x, n);
        double standard = std::cos(x);

        std::cout << "cos(" << x << ") через ряд Тейлора: " << taylor<< std::endl;
        std::cout << "cos(" << x << ") через стандартную функцию: " << standard << std::endl;
    }

    return 0;
}
