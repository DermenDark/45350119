#include <iostream>

int main() {
    double x,y,z;

    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение y: ";
    std::cin >> y;
    std::cout << "Введите значение z: ";
    std::cin >> z;

    if (x <y+z && y <x+z && z <y+x) {
        std::cout << "треугольник существует! ";
    }
    else{
        std::cout << "нет такого треугольника ";
    }
    return 0;
}
