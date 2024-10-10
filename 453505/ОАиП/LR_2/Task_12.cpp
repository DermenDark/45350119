#include <iostream>

double sqrt(double number) {
    double x = number;
    double y = 1.0;
    double e = 0.000001; // точность

    while (x - y > e) {
        x = (x + y) / 2;
        y = number / x;
    }
    return x;
}

void solve1(double a, double b, double c) {
    double D = b * b - 4 * a * c;

    if (D < 0) {
        std::cout << "Нет действительных корней для уравнения ax^4 + bx^2 + c = 0.\n";
        return;
    }

    double y1 = (-b + sqrt
(D)) / (2 * a);
    double y2 = (-b - sqrt
(D)) / (2 * a);

    bool hasRealRoots = false;

    if (y1 >= 0) {
        std::cout << "Корни x: " << sqrt
    (y1) << " и " << -sqrt
    (y1) << std::endl;
        hasRealRoots = true;
    }

    if (y2 >= 0) {
        std::cout << "Корни x: " << sqrt
    (y2) << " и " << -sqrt
    (y2) << std::endl;
        hasRealRoots = true;
    }

    if (!hasRealRoots) {
        std::cout << "Нет действительных корней x.\n";
    }
}

void solve12(double a, double b, double c, double d, double e) {
    for (double x = -100; x <= 100; x += 0.1) {
        double result = a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
        if (result < 0.001 && result > -0.001) {
            std::cout << "Найден корень x: " << x << std::endl;
        }
    }
}

void solve3(double p, double q) {
    for (double x = -100; x <= 100; x += 0.1) {
        double result = x * x * x + p * x + q;
        if (result < 0.001 && result > -0.001) {
            std::cout << "Найден корень x: " << x << std::endl;
        }
    }
}

int main() {
    int choice;
    std::cout << "Выберите тип уравнения (1, 2 или 3):\n";
    std::cout << "1: ax^4 + bx^2 + c = 0\n";
    std::cout << "2: ax^4 + bx^3 + cx^2 + dx + e = 0\n";
    std::cout << "3: x^3 + px + q = 0\n";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            double a, b, c;
            std::cout << "Введите коэффициенты a, b, c:\n";
            std::cin >> a >> b >> c;
            solve1(a, b, c);
            break;
        }
        case 2: {
            double a, b, c, d, e;
            std::cout << "Введите коэффициенты a, b, c, d, e:\n";
            std::cin >> a >> b >> c >> d >> e;
            solve12(a, b, c, d, e);
            break;
        }
        case 3: {
            double p, q;
            std::cout << "Введите коэффициенты p и q:\n";
            std::cin >> p >> q;
            solve3(p, q);
            break;
        }
        default:
            std::cout << "Неверный выбор.\n";
            break;
    }

    return 0;
}