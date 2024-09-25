#include <iostream>
#include <cmath> // Для функции sin

int main() {
    double start, end, step;

    std::cout << "Введите начальное значение x: ";
    std::cin >> start; // Задаем исходное значение переменной

    std::cout << "Введите конечное значение x: ";
    std::cin >> end; // Задаем конечное значение переменной
    
    std::cout << "Введите шаг: ";
    std::cin >> step; // Задаем шаг, с которым будет изменяться аргумент

    for (double x = start; x <= end; x += step) {
        double y = sin(x); // функция y = sin(x)
        std::cout << x << " | " << y << std::endl; // Выводим значения функции для каждого аргумента (x | y)
    }
    return 0;
}

//    tasks.json (настройки сборки компилятора)
//    launch.json (настройки отладчика)
//    c_cpp_properties.json (путь компилятора и настройки IntelliSense)
